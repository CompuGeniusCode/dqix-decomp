#include <globaldefs.h>
#pragma opt_propagation off

extern "C" void _Z13StartHwDividejj(unsigned int numerator, unsigned int denominator);
extern "C" int _Z19GetDivResultFixed20v(void);

struct InStruct020b9ffc {
    char pad0[0x20];
    short f20;
    short f22;
    char pad24[8];
    unsigned short f2c;
    unsigned short f2e;
};

struct OutStruct020b9ffc {
    int f0;
    int f4;
    char pad8[8];
    int f10;
    int f14;
    char pad18[0x18];
    int f30;
    int f34;
};

// USA: func_020b9ffc  (semantic: ComputeFixedTerms_020b9ffc)
extern "C" ARM void func_020b9ffc(OutStruct020b9ffc* out, InStruct020b9ffc* in) {
    int a = in->f2c << 12;
    int b = in->f2e << 12;
    _Z13StartHwDividejj(b, a);
    out->f0 = in->f22;
    out->f14 = in->f22;
    int q1 = _Z19GetDivResultFixed20v();
    out->f4 = (-(int)in->f20 * q1) >> 12;
    _Z13StartHwDividejj(a, b);
    unsigned short f2cv = in->f2c;
    int sum = in->f20 + in->f22;
    int neg = -sum;
    out->f30 = (f2cv * (0x1000 + neg)) << 3;
    out->f34 = (in->f2e * (in->f20 - in->f22 + 0x1000)) << 3;
    int q2 = _Z19GetDivResultFixed20v();
    out->f10 = (in->f20 * q2) >> 12;
}
