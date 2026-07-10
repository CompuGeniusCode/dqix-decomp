#include <globaldefs.h>

// USA: func_020c4f40
ARM unsigned int GetSubBg0CharBaseAddr(void) {
    unsigned short bg0 = *(volatile unsigned short*)0x4001008;
    int cbb = (bg0 & 0x3c) >> 2;
    return 0x6200000 + (cbb << 14);
}
