#include <globaldefs.h>

// USA: func_020c9754
ARM unsigned int GetCpsrIrqDisableBit(void) {
    unsigned int v;
    asm {
        mrs v, cpsr
        and v, v, #0x80
    }
    return v;
}
