#include <globaldefs.h>

extern "C" unsigned int CountLeadingZeros(unsigned int value);

union DblBits0200c578 { struct { unsigned int lo, hi; } w; double d; };

// USA: func_0200c578
ARM double func_0200c578(unsigned int bits) {
    unsigned int sign = bits & 0x80000000;
    unsigned int exp = (bits >> 0x17) & 0xff;
    unsigned int mant = bits << 9;
    DblBits0200c578 r;

    if (exp == 0) {
        if (mant == 0) {
            r.w.hi = sign;
            r.w.lo = 0;
            return r.d;
        }
        mant = mant >> 1;
        unsigned int shift = CountLeadingZeros(mant);
        mant = mant << shift;
        exp = 1 - shift;
        mant = mant + mant;
    } else if (exp == 0xff) {
        if (mant != 0) {
            r.w.lo = 0xFFFFFFFF;
            r.w.hi = 0x7FFFFFFF;
        } else {
            r.w.hi = 0x7ff00000 | sign;
            r.w.lo = 0;
        }
        return r.d;
    }
    exp += 0x380;
    r.w.lo = mant << 0x14;
    r.w.hi = sign | (mant >> 0xc) | (exp << 0x14);
    return r.d;
}
