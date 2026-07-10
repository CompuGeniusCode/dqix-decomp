#include <globaldefs.h>

extern "C" int func_020c490c(unsigned short* entry);
extern unsigned short data_0211123c;

// USA: func_020c4b10
ARM int DisableSubObjExtPalette020c4b10(void) {
    *(unsigned int*)0x4001000 &= ~0x80000000;
    return func_020c490c(&data_0211123c);
}
