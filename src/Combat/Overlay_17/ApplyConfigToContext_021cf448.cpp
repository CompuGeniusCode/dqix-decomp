#include <globaldefs.h>

extern "C" void func_ov017_021bff8c(int a, int b);

struct Src021cf448 {
    char pad0[4];
    int f4;
    int f8;
    int fc;
    unsigned short f10;
    struct {
        unsigned char flagA : 1;
        unsigned char flagB : 1;
    } bits;
    signed char f13;
};

// USA: func_ov017_021cf448
ARM void ApplyConfigToContext_021cf448(int unused, Src021cf448* src, unsigned char* base, int extra) {
    *(int*)(base + 0x7f7c) = src->f4;
    *(int*)(base + 0x7f80) = src->f8;
    *(int*)(base + 0x7f84) = src->fc;
    *(unsigned short*)(base + 0x7f88) = src->f10;
    base[0x7f74] = src->bits.flagA;
    base[0x7f75] = src->bits.flagB;
    if (base[0x7f74] != 0) {
        func_ov017_021bff8c(extra, src->f13);
    }
}
