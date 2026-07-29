#include <globaldefs.h>

// USA: func_020c1868
ARM void CopyVec3ToVec4Array020c1868(unsigned int* src, unsigned int* dst) {
    unsigned int s0 = *src++;
    unsigned int s1 = *src++;
    unsigned int s2 = *src++;
    *dst++ = s0;
    *dst++ = s1;
    *dst++ = s2;
    *dst++ = 0;
    unsigned int t0 = *src++;
    unsigned int t1 = *src++;
    unsigned int t2 = *src++;
    *dst++ = t0;
    *dst++ = t1;
    *dst++ = t2;
    *dst++ = 0;
    unsigned int u0 = *src++;
    unsigned int u1 = *src++;
    unsigned int u2 = *src++;
    *dst++ = u0;
    *dst++ = u1;
    *dst++ = u2;
    *dst++ = 0;
    unsigned int v0 = *src++;
    unsigned int v1 = *src++;
    unsigned int v2 = *src++;
    *dst++ = v0;
    *dst++ = v1;
    *dst++ = v2;
    *dst++ = 0x1000;
}
