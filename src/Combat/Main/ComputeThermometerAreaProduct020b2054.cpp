#include <globaldefs.h>

// USA: func_020b2054
extern "C" ARM unsigned int func_020b2054(unsigned int a, unsigned int b) {
    unsigned int a3 = a >> 3;
    unsigned int b3 = b >> 3;
    unsigned int aLow = ((a & 2) >> 1) + (a & 1);
    unsigned int aBit2 = a & 4;
    unsigned int aX = (aLow << 1) + (aBit2 >> 2);
    unsigned int bLow = ((b & 2) >> 1) + (b & 1);
    unsigned int bBit2 = b & 4;
    unsigned int bX = (bLow << 1) + (bBit2 >> 2);
    unsigned int aH = aLow + (aBit2 >> 2);
    unsigned int bH = bLow + (bBit2 >> 2);
    unsigned int result = 0;
    result = a3 * b3 + result;
    result = b3 * aX + result;
    result = a3 * bX + result;
    result = aH * bH + result;
    return result;
}
