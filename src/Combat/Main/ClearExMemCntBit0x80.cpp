#include <globaldefs.h>

// USA: func_020c6fe0
ARM unsigned int ClearExMemCntBit0x80(void) {
    volatile unsigned short* reg = (volatile unsigned short*)0x4000204;
    unsigned int v = *reg & ~0x80;
    *reg = v;
    return v;
}
