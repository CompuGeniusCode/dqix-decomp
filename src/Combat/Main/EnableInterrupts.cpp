#include <globaldefs.h>

// USA: func_020c96e8
ARM unsigned int EnableInterrupts() {
    unsigned int intr, tmp;
    asm {
        mrs intr, cpsr
        bic tmp, intr, #0x80
        msr cpsr_c, tmp
        and intr, intr, #0x80
    }
    return intr;
}
