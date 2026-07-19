#include <globaldefs.h>

struct InitTarget0205cfd4;
extern void InitStruct0205cfd4(struct InitTarget0205cfd4* s);

struct List0204af64 {
    char pad0[0xc];
    unsigned char b0c;
    unsigned char pad0d;
    unsigned short h0e;
    int w10;
    int w14;
    int w18;
    unsigned char b1c_lo : 4;
    unsigned char b1c_hi : 4;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;
};
extern void ResetList0204af64(struct List0204af64* obj);

extern "C" void func_0204c684(void*);

// USA: func_ov017_021a5b48
ARM void InitFieldArenaLists_021a5b48(unsigned char* base) {
    InitStruct0205cfd4(*(struct InitTarget0205cfd4**)(base + 0x4090));
    for (int i = 0; i < 2; i++) {
        ResetList0204af64((struct List0204af64*)(base + 0x4094 + i * 0x20));
    }
    func_0204c684(base + 0x40d4);
    *(int*)(base + 0x41b8) = 0;
    *(int*)(base + 0x41bc) = -1;
    *(int*)(base + 0x41b4) = 0;
    *(int*)(base + 0x41c0) = 0;
}
