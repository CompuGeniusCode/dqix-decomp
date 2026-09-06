#include <globaldefs.h>

struct SelfBB04b {
    int f0;
    char pad4[4];
    int f8;
    int fc;
    char pad10[4];
    int f14;
    char pad18[0x24 - 0x18];
    int* f24;
    int* f28;
    int* f2c;
};

// USA: func_0205bb04
ARM void ComputeDivisions0205bb04b(int value, struct SelfBB04b* self) {
    int remainder;
    int product;
    if (value < 0) return;
    if (value >= self->f0) return;
    product = self->fc * self->f8;
    if (product == 0) return;
    self->f14 = value / product;
    remainder = value % product;
    *self->f2c = remainder % *self->f24;
    *self->f28 = remainder / *self->f24;
}
