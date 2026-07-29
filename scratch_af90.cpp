#include <globaldefs.h>

// USA: func_0200af90
#pragma optimize_for_size off
extern "C" ARM unsigned int func_0200af90(unsigned int lo, unsigned int hi) {
    if ((int)hi < 0) goto negdouble;
    {
        int shift = 0x41e - (int)(hi >> 0x14);
        if (shift < 0) goto neg;
        if (shift >= 0x20) goto zero;
        {
            unsigned int mant = (hi << 0xb) | 0x80000000u | (lo >> 0x15);
            return mant >> shift;
        }
    }
zero:
    return 0;
negdouble:
    {
        unsigned long long v = ((unsigned long long)hi << 32) | lo;
        return (v > 0xfff0000000000000ULL) ? 0xffffffffu : 0u;
    }
neg:
    return 0xffffffffu;
}
