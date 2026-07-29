#include <globaldefs.h>

struct U64Pair0200afe8 { unsigned int lo, hi; };

// USA: func_0200afe8
ARM struct U64Pair0200afe8 ConvertDoubleToU64_0200afe8(unsigned int lo, unsigned int hi) {
    struct U64Pair0200afe8 r;
    if (hi & 0x80000000) {
        if (hi > 0xfff00000u) { r.lo = 0xffffffffu; r.hi = 0xffffffffu; return r; }
        if (hi == 0xfff00000u && lo != 0) { r.lo = 0xffffffffu; r.hi = 0xffffffffu; return r; }
        r.lo = 0; r.hi = 0;
        return r;
    }
    {
        int shift = 0x43e - (int)(hi >> 20);
        if (shift < 0) { r.lo = 0xffffffffu; r.hi = 0xffffffffu; return r; }
        if (shift >= 0x40) { r.lo = 0; r.hi = 0; return r; }
        unsigned int mant = (hi << 11) | 0x80000000u | (lo >> 21);
        unsigned int lo11 = lo << 11;
        if (shift <= 0x20) {
            r.hi = mant >> shift;
            r.lo = (lo11 >> shift) | (mant << (0x20 - shift));
        } else {
            int s2 = shift - 0x20;
            r.hi = 0;
            r.lo = mant >> s2;
        }
        return r;
    }
}
