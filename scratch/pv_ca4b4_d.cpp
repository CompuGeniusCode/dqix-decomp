#include <globaldefs.h>

extern "C" ARM void F(unsigned int* src, unsigned int* dst, unsigned int size) {
    unsigned int* end = dst + (size >> 2);
    unsigned int* end32 = dst + ((size >> 5) << 3);
    while (dst < end32) {
        unsigned int a = src[0], b = src[1], c = src[2], d = src[3];
        unsigned int e = src[4], f = src[5], g = src[6], h = src[7];
        dst[0]=a; dst[1]=b; dst[2]=c; dst[3]=d;
        dst[4]=e; dst[5]=f; dst[6]=g; dst[7]=h;
        dst += 8;
        src += 8;
    }
    while (dst < end) {
        *dst = *src;
        dst++;
        src++;
    }
}
