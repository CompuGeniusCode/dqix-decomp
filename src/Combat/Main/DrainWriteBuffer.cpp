#include <globaldefs.h>

// USA: func_020c8314
ARM void DrainWriteBuffer(void) {
    asm {
        mov r0, #0
        mcr p15, 0, r0, c7, c10, 4
    }
}
