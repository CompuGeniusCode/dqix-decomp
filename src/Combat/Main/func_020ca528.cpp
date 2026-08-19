#include <globaldefs.h>

// USA: func_020ca528
// PROVENANCE: SonicRushAdventure-Decomp/lib/NitroSDK/src/mi/mi_memory.c — MI_Copy36B. Fixed
// 36-byte block copy, fully unrolled (9 words via ldmia/stmia).
extern "C" ARM asm void func_020ca528(const void* pSrc, void* pDest) {
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}

    bx lr
}
