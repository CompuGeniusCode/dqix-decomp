#include <globaldefs.h>

// USA: func_020c4cc8
ARM unsigned int GetBg1ScreenBaseAddr(void) {
    unsigned short bg1 = *(volatile unsigned short*)0x400000a;
    unsigned int dispcnt = *(volatile unsigned int*)0x4000000;
    int sbb = (bg1 & 0x1f00) >> 8;
    unsigned int base = (((dispcnt & 0x38000000) >> 27) << 16) + 0x6000000;
    return (sbb << 11) + base;
}
