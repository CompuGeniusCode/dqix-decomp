#include <globaldefs.h>

unsigned int CountLeadingZeros(unsigned int value);

union DoubleBits0200b074 {
    struct { unsigned int lo, hi; } w;
    double d;
};

// USA: func_0200b074
ARM double func_0200b074(int val) {
    unsigned int sign = val & 0x80000000;
    if (val < 0) val = -val;
    if (val == 0) return 0.0;
    unsigned int clz = CountLeadingZeros(val);
    unsigned int norm = (unsigned int)val << clz;
    unsigned int exp = 0x41e - clz;
    union DoubleBits0200b074 u;
    u.w.lo = norm << 0x15;
    u.w.hi = sign | ((norm << 1) >> 0xc) | (exp << 0x14);
    return u.d;
}
