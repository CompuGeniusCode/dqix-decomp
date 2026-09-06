#include <globaldefs.h>

extern "C" ARM void F(unsigned int* src, unsigned int* dst, unsigned int size) {
    unsigned int* end = dst + (size >> 2);
    unsigned int* end32 = dst + ((size >> 5) << 3);
    while (dst < end32) {
        dst[0]=src[0]; dst[1]=src[1]; dst[2]=src[2]; dst[3]=src[3];
        dst[4]=src[4]; dst[5]=src[5]; dst[6]=src[6]; dst[7]=src[7];
        dst += 8;
        src += 8;
    }
    while (dst < end) {
        *dst = *src;
        dst++;
        src++;
    }
}
