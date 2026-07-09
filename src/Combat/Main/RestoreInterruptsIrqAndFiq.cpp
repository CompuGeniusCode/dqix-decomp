#include <globaldefs.h>

// USA: func_020c973c
ARM unsigned int RestoreInterruptsIrqAndFiq(unsigned int mask) {
    unsigned int intr, tmp, ret;
    asm {
        mrs intr, cpsr
        bic tmp, intr, #0xc0
        orr tmp, tmp, mask
        msr cpsr_c, tmp
        and ret, intr, #0xc0
    }
    return ret;
}
