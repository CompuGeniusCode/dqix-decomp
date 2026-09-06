#include <globaldefs.h>

// USA: func_020ca408
ARM void CopyWordRange020ca408(unsigned int* src, unsigned int* dst, int byteCount) {
    unsigned int* end = (unsigned int*)((char*)dst + byteCount);
    while (dst < end) {
        unsigned int v = *src++;
        *dst++ = v;
    }
}
