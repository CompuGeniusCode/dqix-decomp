#include <globaldefs.h>

extern "C" void func_020c64a0(void);
extern "C" void func_020c64fc(void* ptr, int a, int b);
extern "C" void func_020c663c(void);

struct Obj020b2e78 {
    char pad0[8];
    int f8;
    unsigned short fc;
    char pad_e[2];
    unsigned short f10;
    char pad_12[2];
    int f14;
    int f18;
    unsigned short f1c;
    char pad_1e[2];
    unsigned short f20;
    char pad_22[2];
    int f24;
    int f28;
};

// USA: func_020b2e78  (semantic: UpdateSlotFlagsAndDispatch_020b2e78)
extern "C" ARM void func_020b2e78(Obj020b2e78* obj, int finalize) {
    if (finalize) {
        func_020c64a0();
    }
    unsigned int scaled_fc = obj->fc << 3;
    if (scaled_fc != 0) {
        unsigned int wide8 = (unsigned int)obj->f8 << 16;
        unsigned int scaled_f8 = wide8 >> 13;
        func_020c64fc((char*)obj + obj->f14, scaled_f8, scaled_fc);
        obj->f10 |= 1;
    }
    unsigned int scaled_f1c = obj->f1c << 3;
    if (scaled_f1c != 0) {
        unsigned int wide18;
        void* ptr28 = (char*)obj + obj->f28;
        wide18 = (unsigned int)obj->f18 << 16;
        unsigned int scaled_f18 = wide18 >> 13;
        func_020c64fc((char*)obj + obj->f24, scaled_f18, scaled_f1c);
        unsigned int part1 = (0x1ffff & (wide18 >> 13)) >> 1;
        unsigned int part2 = (scaled_f18 & 0x40000) >> 2;
        func_020c64fc(ptr28, (part1 + 0x20000) + part2, scaled_f1c >> 1);
        obj->f20 |= 1;
    }
    if (finalize) {
        func_020c663c();
    }
}
