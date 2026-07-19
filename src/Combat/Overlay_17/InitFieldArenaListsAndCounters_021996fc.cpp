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

// USA: func_ov017_021996fc
ARM void InitFieldArenaListsAndCounters_021996fc(unsigned char* base) {
    InitStruct0205cfd4(*(struct InitTarget0205cfd4**)(base + 0x3000 + 0xcb0));

    for (int i = 0; i < 2; i++) {
        ResetList0204af64((struct List0204af64*)(base + 0xb4 + 0x3c00 + i * 0x20));
    }

    for (int j = 0; j < 4; j++) {
        func_0204c684(base + 0xf4 + 0x3c00 + j * 0xe0);
    }

    *(int*)(base + 0x4000 + 0x74) = 0;
    *(int*)(base + 0x4000 + 0x78) = 0;
    *(int*)(base + 0x4000 + 0x7c) = -1;
    *(int*)(base + 0x4000 + 0x80) = 0;
    *(int*)(base + 0x4000 + 0x84) = 0;
}
