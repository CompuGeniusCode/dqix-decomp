#include <globaldefs.h>

// USA: func_020ca50c
// PROVENANCE: SonicRushAdventure-Decomp/lib/NitroSDK/src/mi/mi_memory.c — MI_Copy32B. Fixed
// 32-byte block copy, fully unrolled (8 words via ldmia/stmia).
extern "C" ARM asm void func_020ca50c(const void* pSrc, void* pDest) {
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3}
    stmia r1!, {r2, r3}

    bx lr
}
