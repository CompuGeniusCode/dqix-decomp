#include <globaldefs.h>

// USA: func_0206ea8c
ARM void SetOrClearBit0206ea8c(unsigned char* base, int flag, int bitIndex, int setMode) {
    int bit = (bitIndex & 7) ^ 7;
    int region = flag & 1;
    int byteIndex = bitIndex >> 3;
    if (setMode != 0) {
        unsigned char* p = base + 0x41b + (region << 5);
        p[byteIndex] = p[byteIndex] | (1 << bit);
    } else {
        unsigned char* p = base + 0x41b + (region << 5);
        p[byteIndex] = p[byteIndex] & ~(1 << bit);
    }
}
