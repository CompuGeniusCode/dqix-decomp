#include <globaldefs.h>

// USA: func_020c96fc
ARM unsigned int DisableInterrupts() {
    unsigned int intr, tmp;
    asm {
        mrs intr, cpsr
        orr tmp, intr, #0x80
        msr cpsr_c, tmp
        and intr, intr, #0x80
    }
    return intr;
}
