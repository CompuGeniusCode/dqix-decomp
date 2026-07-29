#include <globaldefs.h>

extern "C" unsigned int CountLeadingZeros(unsigned int value);

union DblBits0200c578 { struct { unsigned int lo, hi; } w; double d; };

// USA: func_0200c578
ARM double func_0200c578(float f) {
    union { float f; unsigned int u; } cv;
    unsigned int sign, exp, mant, lo, hi;
    DblBits0200c578 r;
    cv.f = f;
    sign = cv.u & 0x80000000;
    exp = (cv.u >> 0x17) & 0xff;
    mant = cv.u << 9;

    if (exp == 0) {
        if (mant == 0) {
            hi = sign;
            lo = 0;
            r.w.lo = lo; r.w.hi = hi;
            return r.d;
        }
        mant = mant >> 1;
        unsigned int shift = CountLeadingZeros(mant);
        mant = mant << shift;
        exp = 1 - shift;
        mant = mant + mant;
    } else if (exp == 0xff) {
        if (mant != 0) {
            lo = 0xFFFFFFFF;
            hi = 0x7FFFFFFF;
        } else {
            hi = 0x7ff00000 | sign;
            lo = 0;
        }
        r.w.lo = lo; r.w.hi = hi;
        return r.d;
    }
    exp += 0x380;
    lo = mant << 0x14;
    hi = sign | (mant >> 0xc) | (exp << 0x14);
    r.w.lo = lo; r.w.hi = hi;
    return r.d;
}
