#include <globaldefs.h>

struct W1_regtest14 { unsigned int v; };

ARM void TestStructLoopCopy_regtest14(W1_regtest14* src, W1_regtest14* dst, int byteCount) {
    W1_regtest14* end = (W1_regtest14*)((char*)dst + byteCount);
    while (dst < end) {
        *dst = *src;
        src++;
        dst++;
    }
}
