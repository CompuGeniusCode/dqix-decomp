#include <globaldefs.h>

// USA: func_020ca568
// PROVENANCE: SonicRushAdventure-Decomp/lib/NitroSDK/src/mi/mi_memory.c — MI_Copy64B. Fixed
// 64-byte block copy, fully unrolled (16 words via ldmia/stmia).
extern "C" ARM asm void func_020ca568(const void* pSrc, void* pDest) {
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0, {r0, r2, r3, r12}
    stmia r1!, {r0, r2, r3, r12}

    bx lr
}
