#include <globaldefs.h>

ARM void SetBitfield0205af84(int a, void* b, int c);
extern "C" void func_0205ac40(int a, void* b);

extern unsigned char data_ov008_0218b30c;
extern signed char data_ov008_0218b300;
extern int data_ov008_0218b314;

struct Actor02188934 {
    char pad0[0x730];
    int f0x730;
    void* f0x734;
    char pad2[0x74c - 0x738];
    unsigned char f0x74c;
    char pad3[0xb18 - 0x74d];
    int f0xb18;
    char pad4[0xb29 - 0xb1c];
    unsigned char f0xb29;
};

// USA: func_02188934
ARM void ApplyScaleEntries_02188934(struct Actor02188934* obj) {
    if (obj->f0x730 == 0) return;
    if (!(obj->f0xb18 & 0x10)) return;
    if (!(obj->f0xb18 & 0x80000)) return;

    int idx;
    for (idx = 0; idx < 2; idx++) {
        unsigned char c1 = obj->f0x74c;
        unsigned char c2 = obj->f0xb29;
        if (c1 == 7 && c2 == 1) c2 = 2;
        unsigned char flag = (&data_ov008_0218b30c)[c2 * 2 + idx];
        if (flag == 0) continue;
        signed char scaleVal = (&data_ov008_0218b300)[idx];
        char* base = (char*)obj->f0x734;
        int off = scaleVal * 0x28;
        *(int*)(base + off + 0x14) = 0x46000;
        int wordVal = (&data_ov008_0218b314)[idx];
        *(int*)(base + off + 0x18) = wordVal;
        SetBitfield0205af84(obj->f0x730, (char*)obj->f0x734 + off, 1);
        func_0205ac40(obj->f0x730, (char*)obj->f0x734 + off);
    }
}
