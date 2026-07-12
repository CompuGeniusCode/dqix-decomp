#include <globaldefs.h>

// USA: func_020c824c
ARM void InvalidateDataCacheAll(void) {
    asm {
        mov r0, #0
        mcr p15, 0, r0, c7, c6, 0
    }
}
