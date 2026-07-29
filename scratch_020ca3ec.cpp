#include <globaldefs.h>

// USA: func_020ca3ec
ARM void FillWords_020ca3ec(unsigned int value, unsigned int* dst, int byteLen) {
    unsigned int* end = (unsigned int*)((char*)dst + byteLen);
    goto test;
body:
    *dst = value;
    dst = (unsigned int*)((char*)dst + 4);
test:
    if (dst < end) goto body;
}
