#include <globaldefs.h>

extern "C" int func_020c490c(unsigned short* entry);
extern unsigned short data_0211123a;

// USA: func_020c4ae8
ARM int DisableSubBgExtPalette020c4ae8(void) {
    *(unsigned int*)0x4001000 &= ~0x40000000;
    return func_020c490c(&data_0211123a);
}
