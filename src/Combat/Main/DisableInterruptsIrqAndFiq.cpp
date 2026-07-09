#include <globaldefs.h>

// USA: func_020c9728
ARM unsigned int DisableInterruptsIrqAndFiq() {
    unsigned int intr, tmp;
    asm {
        mrs intr, cpsr
        orr tmp, intr, #0xc0
        msr cpsr_c, tmp
        and intr, intr, #0xc0
    }
    return intr;
}
