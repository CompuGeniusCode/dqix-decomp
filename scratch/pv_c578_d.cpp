#include <globaldefs.h>

extern "C" unsigned int CountLeadingZeros(unsigned int value);

// USA: func_0200c578
ARM double func_0200c578(unsigned int bits) {
    unsigned int sign = bits & 0x80000000;
    unsigned int exp = (bits >> 0x17) & 0xff;
    unsigned int mant = bits << 9;
    unsigned int lo, hi;

    if (exp == 0) {
        if (mant == 0) {
            hi = sign;
            lo = 0;
            unsigned long long combined = ((unsigned long long)hi << 32) | lo;
            return *(double*)&combined;
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
        unsigned long long combined = ((unsigned long long)hi << 32) | lo;
        return *(double*)&combined;
    }
    exp += 0x380;
    lo = mant << 0x14;
    hi = sign | (mant >> 0xc) | (exp << 0x14);
    unsigned long long combined = ((unsigned long long)hi << 32) | lo;
    return *(double*)&combined;
}
