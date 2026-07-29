#include <globaldefs.h>

#pragma optimize_for_size off

extern "C" void *func_020b736c(void *a0, int a1, void *a2, int a3);

struct PairB9850 {
    unsigned short f0;
    unsigned short f2;
};

struct ObjB9850 {
    char pad1[0x2c];
    unsigned int field2c;
    char pad2[0x34 - 0x30];
    unsigned short field34;
};

// USA: func_020b9850  (semantic: ComputeHalvedSum020b9850)
extern "C" ARM void func_020b9850(ObjB9850 *a0, int a1, void *a2, int a3) {
    PairB9850 *r;
    if (a0 != 0 && a0->field34 != 0) {
        r = (PairB9850 *)func_020b736c((char *)a0 + a0->field34, a1, a2, a3);
    } else {
        r = (PairB9850 *)0;
    }
    unsigned int v = (unsigned short)a0->field2c;
    v = v & 0x1fffffff;
    unsigned short scaled = (unsigned short)v;
    unsigned short flagField = r->f2;
    unsigned short base = r->f0;
    if (!(flagField & 1)) {
        base = (unsigned short)(base >> 1);
        scaled = (unsigned short)(scaled >> 1);
    }
    *(int *)((char *)a2 + 0x14) = base + scaled;
}
