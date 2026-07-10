#include <globaldefs.h>

// USA: func_020c4cfc
ARM unsigned int GetSubBg1ScreenBaseAddr(void) {
    unsigned short bg1 = *(volatile unsigned short*)0x400100a;
    int sbb = (bg1 & 0x1f00) >> 8;
    return 0x6200000 + (sbb << 11);
}
