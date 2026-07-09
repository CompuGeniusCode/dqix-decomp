#include <globaldefs.h>

// USA: func_020c9710
ARM unsigned int RestoreInterrupts(unsigned int mask) {
    unsigned int intr, tmp, ret;
    asm {
        mrs intr, cpsr
        bic tmp, intr, #0x80
        orr tmp, tmp, mask
        msr cpsr_c, tmp
        and ret, intr, #0x80
    }
    return ret;
}
