#include <globaldefs.h>

// USA: func_0206ea8c
ARM void SetOrClearBit0206ea8c(unsigned char* base, int flag, int bitIndex, int setMode) {
    unsigned short bit = (bitIndex & 7) ^ 7;
    short byteIndex = bitIndex >> 3;
    int region = flag & 1;
    unsigned char* p = base + 0x41b + (region << 5);
    if (setMode != 0) {
        p[byteIndex] = p[byteIndex] | (1 << bit);
    } else {
        p[byteIndex] = p[byteIndex] & ~(1 << bit);
    }
}
