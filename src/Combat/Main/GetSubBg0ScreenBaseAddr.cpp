#include <globaldefs.h>

// USA: func_020c4ca8
ARM unsigned int GetSubBg0ScreenBaseAddr(void) {
    unsigned short bg0 = *(volatile unsigned short*)0x4001008;
    int sbb = (bg0 & 0x1f00) >> 8;
    return 0x6200000 + (sbb << 11);
}
