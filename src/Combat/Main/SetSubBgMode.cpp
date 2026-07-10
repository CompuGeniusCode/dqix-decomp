#include <globaldefs.h>

// USA: func_020c3984
ARM void SetSubBgMode(unsigned int mode) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    *dispcnt = (*dispcnt & ~7) | mode;
}
