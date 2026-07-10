#include <globaldefs.h>

// USA: func_020c4c74
ARM unsigned int GetBg0ScreenBaseAddr(void) {
    int sbb = (*(volatile unsigned short*)0x4000008 & 0x1f00) >> 8;
    unsigned int dispcnt = *(volatile unsigned int*)0x4000000;
    return 0x6000000 + ((dispcnt & 0x38000000) >> 27 << 16) + (sbb << 11);
}
