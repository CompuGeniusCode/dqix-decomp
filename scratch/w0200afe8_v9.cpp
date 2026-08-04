#include <globaldefs.h>

typedef unsigned long long u64;

// USA: func_0200afe8
ARM u64 ConvertDoubleToU64_0200afe8(unsigned int lo, unsigned int hi) {
    if (hi & 0x80000000) {
        u64 mag = ((u64)hi << 32) | lo;
        if (mag > 0xFFF0000000000000ULL) {
            return 0xffffffffffffffffULL;
        }
        return 0;
    }
    {
        int shift = 0x43e - (int)(hi >> 20);
        if (shift < 0) return 0xffffffffffffffffULL;
        if (shift >= 0x40) return 0;
        unsigned int mant = (hi << 11) | 0x80000000u | (lo >> 21);
        if (shift <= 0x20) {
            unsigned int lo11 = lo << 11;
            unsigned int outHi = mant >> shift;
            unsigned int outLo = (lo11 >> shift) | (mant << (0x20 - shift));
            return ((u64)outHi << 32) | outLo;
        } else {
            int s2 = shift - 0x20;
            return (u64)(mant >> s2);
        }
    }
}
