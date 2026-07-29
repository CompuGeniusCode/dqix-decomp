#include <globaldefs.h>

// USA: func_020ca408
ARM void CopyWordRange020ca408(unsigned int* src, unsigned int* dst, int byteCount) {
    unsigned int* end = (unsigned int*)((char*)dst + byteCount);
    if (dst < end) {
        do {
            *dst++ = *src++;
        } while (dst < end);
    }
}
