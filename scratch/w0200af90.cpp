#include <globaldefs.h>

#pragma optimize_for_size off
// USA: func_0200af90
extern "C" ARM unsigned int func_0200af90(unsigned int lo, unsigned int hi) {
    if (hi & 0x80000000u) goto negative;
    {
        int shift = 0x41e - (int)(hi >> 0x14);
        if (0 > shift) goto allones;
        if (shift >= 0x20) goto zero;
        {
            unsigned int mant = (hi << 0xb) | 0x80000000u | (lo >> 0x15);
            return mant >> shift;
        }
    }
zero:
    return 0u;
allones:
    return 0xFFFFFFFFu;
negative:
    {
        unsigned long long v = ((unsigned long long)hi << 32) | lo;
        return (v > 0xFFF0000000000000ULL) ? 0xFFFFFFFFu : 0u;
    }
}
