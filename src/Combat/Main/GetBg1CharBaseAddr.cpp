#include <globaldefs.h>

// USA: func_020c4f60
ARM unsigned int GetBg1CharBaseAddr(void) {
    volatile unsigned short* bg1cntReg = (volatile unsigned short*)0x400000a;
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    unsigned int cbb = (*bg1cntReg & 0x3c) >> 2;
    unsigned int xbase = ((*dispcnt & 0x7000000) >> 24) << 16;
    return 0x6000000 + xbase + (cbb << 14);
}
