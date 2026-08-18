#include <globaldefs.h>

void SetBitfield0205af84(int a, void* b, int c);
extern "C" void func_0205ac40(int a, void* b);

extern unsigned char data_ov008_0218b30c[][2];
extern signed char data_ov008_0218b300[];
extern int data_ov008_0218b314[];

struct Sub02188934 { char pad[0x14]; unsigned int f14; unsigned int f18; };

struct Obj02188934 {
    char pad0[0x730];
    int f730;
    struct Sub02188934* f734;
    char pad1[0x74c - 0x738];
    unsigned char f74c;
    char pad2[0xb18 - 0x74d];
    unsigned int flags_b18;
    char pad3[0xb29 - 0xb1c];
    unsigned char b29;
};

// USA: func_ov008_02188934
extern "C" ARM void SetupEntriesFromTable_02188934(struct Obj02188934* obj) {
    int i;
    if (obj->f730 == 0) return;
    if (!(obj->flags_b18 & 0x10)) return;
    if (!(obj->flags_b18 & 0x80000)) return;

    for (i = 0; i < 2; i++) {
        int b = obj->b29;
        if (obj->f74c == 7 && b == 1) b = 2;
        unsigned char idx = data_ov008_0218b30c[b][i];
        if (idx == 0) continue;
        signed char c = data_ov008_0218b300[i];
        int d = data_ov008_0218b314[i];
        int sb = c * 0x28;
        struct Sub02188934* s = (struct Sub02188934*)((char*)obj->f734 + sb);
        s->f14 = 0x46000;
        s->f18 = d;
        SetBitfield0205af84(obj->f730, (char*)obj->f734 + sb, 1);
        func_0205ac40(obj->f730, (char*)obj->f734 + sb);
    }
}
