#include <globaldefs.h>

// USA: func_020c4d1c
ARM unsigned int GetBgCharBaseAddress020c4d1c(void) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    volatile unsigned short* bgcntReg = (volatile unsigned short*)0x400000c;
    unsigned int mode = *dispcnt & 7;
    unsigned int bgcnt = *bgcntReg;
    unsigned int screenBase = (*dispcnt & 0x38000000) >> 27;
    unsigned int base = screenBase << 16;
    unsigned int charBase = (bgcnt & 0x1f00) >> 8;
    switch (mode) {
    case 0: case 1: case 2: case 3: case 4:
        return 0x6000000 + base + (charBase << 11);
    case 5:
        if (bgcnt & 0x80)
            return 0x6000000 + (charBase << 14);
        return 0x6000000 + base + (charBase << 11);
    case 6:
        return 0x6000000;
    default:
        return 0;
    }
}
