#include <globaldefs.h>

// USA: func_020c7060
ARM unsigned int SetExMemCntBit0x800(void) {
    volatile unsigned short* reg = (volatile unsigned short*)0x4000204;
    unsigned int v = *reg | 0x800;
    *reg = v;
    return v;
}
