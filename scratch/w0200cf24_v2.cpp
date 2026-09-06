#include <globaldefs.h>

// USA: func_0200cf24
ARM unsigned long long Multiply64_0200cf24(unsigned long long a, unsigned long long b) {
    unsigned int lo, hi;
    unsigned long long p = (unsigned long long)(unsigned int)a * (unsigned int)b;
    lo = (unsigned int)p;
    hi = (unsigned int)(p >> 32);
    hi += (unsigned int)a * (unsigned int)(b >> 32);
    hi += (unsigned int)(a >> 32) * (unsigned int)b;
    return ((unsigned long long)hi << 32) | lo;
}
