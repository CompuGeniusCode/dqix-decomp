#include <globaldefs.h>

// USA: func_0206ea8c
ARM void SetOrClearBit0206ea8c(unsigned char* base, int flag, int bitIndex, int setMode) {
    unsigned short bit = (bitIndex & 7) ^ 7;
    short byteIndex = bitIndex >> 3;
    int region = flag & 1;
    unsigned char* rowBase = base + 0x41b;
    if (setMode != 0) {
        rowBase[(region << 5) + byteIndex] = rowBase[(region << 5) + byteIndex] | (1 << bit);
    } else {
        rowBase[(region << 5) + byteIndex] = rowBase[(region << 5) + byteIndex] & ~(1 << bit);
    }
}
