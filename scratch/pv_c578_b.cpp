#include <globaldefs.h>

extern "C" unsigned int CountLeadingZeros(unsigned int value);

struct DblWords0200c578 { unsigned int lo, hi; };

// USA: func_0200c578
ARM DblWords0200c578 func_0200c578(float f) {
    union { float f; unsigned int u; } cv;
    unsigned int sign, exp, mant;
    DblWords0200c578 r;
    cv.f = f;
    sign = cv.u & 0x80000000;
    exp = (cv.u >> 0x17) & 0xff;
    mant = cv.u << 9;

    if (exp == 0) {
        if (mant == 0) {
            r.hi = sign;
            r.lo = 0;
            return r;
        }
        mant = mant >> 1;
        unsigned int shift = CountLeadingZeros(mant);
        mant = mant << shift;
        exp = 1 - shift;
        mant = mant + mant;
    } else if (exp == 0xff) {
        if (mant != 0) {
            r.lo = 0xFFFFFFFF;
            r.hi = 0x7FFFFFFF;
        } else {
            r.hi = 0x7ff00000 | sign;
            r.lo = 0;
        }
        return r;
    }
    exp += 0x380;
    r.lo = mant << 0x14;
    r.hi = sign | (mant >> 0xc) | (exp << 0x14);
    return r;
}
