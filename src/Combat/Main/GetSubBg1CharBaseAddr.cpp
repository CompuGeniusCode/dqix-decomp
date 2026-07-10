#include <globaldefs.h>

// USA: func_020c4f94
ARM unsigned int GetSubBg1CharBaseAddr(void) {
    volatile unsigned short* bg1cntReg = (volatile unsigned short*)0x400100a;
    int bg1 = *bg1cntReg;
    unsigned int cbb = (bg1 & 0x3c) >> 2;
    return 0x6200000 + (cbb << 14);
}
