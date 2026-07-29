#include <globaldefs.h>

// USA: func_0200cf24
extern "C" ARM long long func_0200cf24(long long a, long long b) {
    unsigned int aLo = (unsigned int)a;
    int aHi = (int)(a >> 32);
    unsigned int bLo = (unsigned int)b;
    int bHi = (int)(b >> 32);
    unsigned long long lo64 = (unsigned long long)aLo * (unsigned long long)bLo;
    unsigned int lo = (unsigned int)lo64;
    unsigned int hi = (unsigned int)(lo64 >> 32);
    hi += aLo * bHi;
    hi += bLo * aHi;
    return ((long long)(int)hi << 32) | lo;
}
