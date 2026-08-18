#include <globaldefs.h>

// USA: func_ov023_021f6c3c
extern "C" ARM void ClearFlagRun_021f6c3c(int* obj, int idx, unsigned int start, unsigned int count) {
    if (start >= 0x80) return;
    int* p = obj + 2 + idx * 4;
    unsigned short i;
    for (i = 0; i < count; i++) {
        unsigned int wordIdx = start >> 2;
        unsigned int bit = start & 3;
        int* addr = p + wordIdx;
        *addr = *addr & ~(1 << bit);
        start++;
    }
}
