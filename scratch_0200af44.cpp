#include <globaldefs.h>

// USA: func_0200af44
ARM int ConvertDoubleToInt_0200af44(unsigned int lo, unsigned int hi) {
    unsigned int exp = (hi & 0x7fffffff) >> 20;
    if (0x41e - (int)exp <= 0) goto denorm;
    int shift = 0x41e - exp;
    if (shift >= 0x20) goto zero;
    {
        unsigned int mantissa = (hi << 11) | 0x80000000 | (lo >> 21);
        int result = (int)(mantissa >> shift);
        if ((int)hi < 0) result = -result;
        return result;
    }
zero:
    return 0;
denorm:
    return (~((int)hi >> 31)) + 0x80000000;
}
