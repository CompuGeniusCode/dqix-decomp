#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" ARM void F(char* src, char* dst, unsigned int size) {
    char* end = dst + size;
    char* end32 = dst + ((size >> 5) << 5);
    while (dst < end32) {
        memcpy(dst, src, 32);
        dst += 32;
        src += 32;
    }
    while (dst < end) {
        *(unsigned int*)dst = *(unsigned int*)src;
        dst += 4;
        src += 4;
    }
}
