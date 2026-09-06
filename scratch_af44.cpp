#include <globaldefs.h>

// USA: func_0200af44
extern "C" ARM int func_0200af44(unsigned int lo, unsigned int hi) {
    unsigned int masked = hi & ~0x80000000u;
    int shift;
    shift = 0x41e - (masked >> 0x14);
    if (shift <= 0) goto overflow;
    if (shift >= 0x20) goto zero;
    {
        unsigned int mant = (hi << 0xb) | 0x80000000u | (lo >> 0x15);
        int result = (int)(mant >> shift);
        if ((int)hi < 0) result = -result;
        return result;
    }
zero:
    return 0;
overflow:
    return (~((int)hi >> 0x1f)) + (int)0x80000000;
}
