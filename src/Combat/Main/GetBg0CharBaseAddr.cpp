#include <globaldefs.h>

// USA: func_020c4f0c
ARM unsigned int GetBg0CharBaseAddr(void) {
    unsigned short bg0 = *(volatile unsigned short*)0x4000008;
    unsigned int dispcnt = *(volatile unsigned int*)0x4000000;
    int cbb = (bg0 & 0x3c) >> 2;
    unsigned int base = (((dispcnt & 0x7000000) >> 24) << 16) + 0x6000000;
    return (cbb << 14) + base;
}
