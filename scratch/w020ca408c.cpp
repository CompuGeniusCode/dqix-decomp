#include <globaldefs.h>

// USA: func_020ca408
ARM void CopyWordRange020ca408(unsigned int* src, unsigned int* dst, int byteCount) {
    unsigned int* end = (unsigned int*)((char*)dst + byteCount);
LOOP:
    if (dst < end) goto DO_LOAD; else goto END;
DO_LOAD:
    {
    unsigned int tmp = *src++;
    if (dst < end) goto DO_STORE; else goto END;
DO_STORE:
    *dst++ = tmp;
    }
    if (dst < end) goto LOOP;
END:
    return;
}
