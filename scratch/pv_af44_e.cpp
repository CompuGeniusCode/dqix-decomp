#include <globaldefs.h>

#pragma optimize_for_size off
extern "C" ARM int F(unsigned int lo, unsigned int hi) {
    unsigned int absHi = hi & 0x7fffffffu;
    int shift = 0x41e - (int)(absHi >> 0x14);
    if (shift <= 0) {
        return ~(((int)hi) >> 31) + (int)0x80000000;
    }
    if (shift >= 0x20) {
        return 0;
    }
    unsigned int mant = (hi << 0xb) | 0x80000000u | (lo >> 0x15);
    int result = (int)(mant >> shift);
    if ((int)hi < 0) {
        result = -result;
    }
    return result;
}
