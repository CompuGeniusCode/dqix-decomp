#include <globaldefs.h>

#pragma opt_arithtransformation off

// USA: func_ov023_021f6c3c
ARM void ClearBitRange_021f6c3c(void* base, unsigned int idx1, unsigned int startBit,
                                unsigned int count) {
    if (startBit >= 0x80) {
        return;
    }
    unsigned short i = 0;
    while (i < count) {
        unsigned int* arr = (unsigned int*)((char*)base + 8 + (idx1 << 4));
        unsigned int word = arr[startBit >> 2];
        unsigned int mask = ~(1u << (startBit & 3));
        arr[startBit >> 2] = word & mask;
        startBit++;
        i++;
    }
}
