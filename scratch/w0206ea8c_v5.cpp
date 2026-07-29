#include <globaldefs.h>

// USA: func_0206ea8c
ARM void SetOrClearBit0206ea8c(unsigned char* base, int flag, int bitIndex, int setMode) {
    unsigned short bit = (bitIndex & 7) ^ 7;
    int region = flag & 1;
    short byteIndex = bitIndex >> 3;
    unsigned char* rowBase = base + 0x41b;
    if (setMode != 0) {
        unsigned char* p = rowBase + (region << 5);
        p[byteIndex] = p[byteIndex] | (1 << bit);
    } else {
        unsigned char* p = rowBase + (region << 5);
        p[byteIndex] = p[byteIndex] & ~(1 << bit);
    }
}
