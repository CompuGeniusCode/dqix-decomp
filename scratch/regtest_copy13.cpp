#include <globaldefs.h>

ARM void TestPtrLoop_regtest13(unsigned int* src, unsigned int* dst, int byteCount) {
    unsigned int* end = (unsigned int*)((char*)dst + byteCount);
    while (dst < end) {
        *dst = *src;
        src++;
        dst++;
    }
}
