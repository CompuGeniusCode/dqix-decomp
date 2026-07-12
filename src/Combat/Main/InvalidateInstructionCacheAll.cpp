#include <globaldefs.h>

// USA: func_020c8320
ARM void InvalidateInstructionCacheAll(void) {
    asm {
        mov r0, #0
        mcr p15, 0, r0, c7, c5, 0
    }
}
