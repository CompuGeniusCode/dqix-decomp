#include <globaldefs.h>

typedef unsigned long long u64;
typedef union { u64 v; struct { unsigned int lo, hi; } w; } U64Bits0200afe8;

// USA: func_0200afe8
ARM u64 ConvertDoubleToU64_0200afe8(unsigned int lo, unsigned int hi) {
    U64Bits0200afe8 r;
    if (hi & 0x80000000) {
        if (hi > 0xfff00000u) { r.w.lo = 0xffffffffu; r.w.hi = 0xffffffffu; return r.v; }
        if (hi == 0xfff00000u && lo != 0) { r.w.lo = 0xffffffffu; r.w.hi = 0xffffffffu; return r.v; }
        r.w.lo = 0; r.w.hi = 0;
        return r.v;
    }
    {
        int shift = 0x43e - (int)(hi >> 20);
        if (shift < 0) { r.w.lo = 0xffffffffu; r.w.hi = 0xffffffffu; return r.v; }
        if (shift >= 0x40) { r.w.lo = 0; r.w.hi = 0; return r.v; }
        unsigned int mant = (hi << 11) | 0x80000000u | (lo >> 21);
        unsigned int lo11 = lo << 11;
        if (shift <= 0x20) {
            r.w.hi = mant >> shift;
            r.w.lo = (lo11 >> shift) | (mant << (0x20 - shift));
        } else {
            int s2 = shift - 0x20;
            r.w.hi = 0;
            r.w.lo = mant >> s2;
        }
        return r.v;
    }
}
