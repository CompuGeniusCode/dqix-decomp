#include <globaldefs.h>

struct Block32 { unsigned int a,b,c,d,e,f,g,h; };

extern "C" ARM void F(char* src, char* dst, unsigned int size) {
    char* end = dst + size;
    char* end32 = dst + ((size >> 5) << 5);
    while (dst < end32) {
        *(Block32*)dst = *(Block32*)src;
        dst += 32;
        src += 32;
    }
    while (dst < end) {
        *(unsigned int*)dst = *(unsigned int*)src;
        dst += 4;
        src += 4;
    }
}
