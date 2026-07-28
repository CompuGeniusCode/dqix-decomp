#include <globaldefs.h>

// USA: func_ov023_021f1818  (semantic: SetSubEngineModeFlag_021f1818)
extern "C" ARM void func_ov023_021f1818(char* obj, int enable) {
    obj += 0x1d00;
    volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
    if (enable) {
        *(unsigned short*)(obj + 0x72) |= 0x80;
        *reg = (*reg & ~0x1f00) | 0x200;
    } else {
        *(unsigned short*)(obj + 0x72) &= ~0x80;
        *reg = (*reg & ~0x1f00) | 0x1700;
    }
}
