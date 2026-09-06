#include <globaldefs.h>

// USA: func_020ca544
// PROVENANCE: SonicRushAdventure-Decomp/lib/NitroSDK/src/mi/mi_memory.c — MI_Copy48B. Fixed
// 48-byte block copy, fully unrolled (12 words via ldmia/stmia).
extern "C" ARM asm void func_020ca544(const void* pSrc, void* pDest) {
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}

    bx lr
}
