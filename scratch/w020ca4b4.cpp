#include <globaldefs.h>

// USA: func_020ca4b4
extern "C" ARM void CopyMemoryBlocks020ca4b4(unsigned int* src, unsigned int* dst, unsigned int size) {
    unsigned int* end32 = dst + ((size >> 5) << 3);
    unsigned int* end = (unsigned int*)((char*)dst + size);
    while (dst < end32) {
        unsigned int a=src[0],b=src[1],c=src[2],d=src[3],e=src[4],f=src[5],g=src[6],h=src[7];
        src += 8;
        dst[0]=a;dst[1]=b;dst[2]=c;dst[3]=d;dst[4]=e;dst[5]=f;dst[6]=g;dst[7]=h;
        dst += 8;
    }
    while (dst < end) {
        unsigned int v = *src;
        src++;
        *dst = v;
        dst++;
    }
}
