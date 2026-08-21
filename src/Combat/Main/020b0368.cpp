#include <globaldefs.h>
#include "System/Cache.h"

extern "C" void func_020c64a0(void);
extern "C" void func_020c64fc(void* ptr, int a, int b);
extern "C" void func_020c663c(void);
extern "C" int _Z32TransferMainObjCharData_020c5a28iij(int arg0, int arg1, unsigned int arg2);
extern "C" int func_020c5a80(int, int, unsigned int);
extern "C" void _Z26SetIntArrayElement020b0334Piii(int* arr, int index, int value);

struct LocalRes020b0368 {
    unsigned short f0;
    unsigned short f2;
    int f4;
    unsigned int f8;
    char padc[4];
    unsigned int f10;
    void* f14;
};

struct Obj020b0368 {
    char pad0[0xc];
    int f0xc;
    int f0x10;
    int f0x14;
    int f0x18;
    int f0x1c;
    int f0x20;
};

// USA: func_020b0368
#pragma optimize_for_size off
extern "C" ARM void func_020b0368(int local, int val44, int tier, void* objPtr) {
    struct LocalRes020b0368* res = (struct LocalRes020b0368*)local;
    struct Obj020b0368* out = (struct Obj020b0368*)objPtr;
    unsigned int flag8 = res->f8;

    if (tier != 0) {
        switch (tier) {
        case 1:
            *(volatile unsigned int*)0x04000000 = (*(volatile unsigned int*)0x04000000 & 0xffcfffef) | flag8;
            break;
        case 2:
            *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & 0xffcfffef) | flag8;
            break;
        }
    }

    CleanInvalidateCacheRange(res->f14, res->f10);

    switch (tier) {
    case 0:
        func_020c64a0();
        func_020c64fc(res->f14, val44, res->f10);
        func_020c663c();
        break;
    case 1:
        _Z32TransferMainObjCharData_020c5a28iij((int)res->f14, val44, res->f10);
        break;
    case 2:
        func_020c5a80((int)res->f14, val44, res->f10);
        break;
    }

    if (res->f8 == 0) {
        int idx;
        switch (res->f2) {
        case 1: idx = 0; break;
        case 2: idx = 1; break;
        case 4: idx = 2; break;
        case 8: idx = 3; break;
        case 16: idx = 4; break;
        case 32: idx = 5; break;
        default: idx = 0; break;
        }
        out->f0xc = idx;

        switch (res->f0) {
        case 1: idx = 0; break;
        case 2: idx = 1; break;
        case 4: idx = 2; break;
        case 8: idx = 3; break;
        case 16: idx = 4; break;
        case 32: idx = 5; break;
        default: idx = 0; break;
        }
        out->f0x10 = idx;
    } else {
        out->f0xc = res->f2;
        out->f0x10 = res->f0;
    }

    out->f0x14 = res->f4;
    out->f0x18 = 0;
    out->f0x1c = 1;
    out->f0x20 = res->f8;
    _Z26SetIntArrayElement020b0334Piii((int*)out, tier, val44);
}
