#include <globaldefs.h>

// USA: func_020c8258
ARM void CleanDataCacheAll(void) {
    asm {
        mov r1, #0
    loop1:
        mov r0, #0
    loop2:
        orr r2, r1, r0
        mcr p15, 0, r2, c7, c10, 2
        add r0, r0, #0x20
        cmp r0, #0x400
        blt loop2
        add r1, r1, #0x40000000
        cmp r1, #0
        bne loop1
    }
}
