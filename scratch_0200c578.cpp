#include <globaldefs.h>

// USA: func_0200c578
ARM long long func_0200c578(unsigned int f) {
    unsigned int sign = f & 0x80000000;
    unsigned int exp = (f >> 23) & 0xff;
    unsigned int mant = f << 9;
    unsigned int loWord;
    unsigned int hiWord;

    if (exp == 0) {
        if (mant != 0) {
            mant = mant >> 1;
            {
                unsigned int shift;
                asm {
                    clz shift, mant
                    mov mant, mant, lsl shift
                }
                exp = 1 - shift;
                mant = mant + mant;
            }
            goto normal;
        }
        return (long long)sign << 32;
    }
    if (exp == 0xff) {
        if (mant != 0) {
            return ((long long)0x7fffffff << 32) | 0xffffffffu;
        }
        return (long long)(0x7ff00000 | sign) << 32;
    }

normal:
    exp = exp + 0x380;
    loWord = mant << 20;
    hiWord = sign | (mant >> 12);
    hiWord = hiWord | (exp << 20);
    return ((long long)hiWord << 32) | loWord;
}
