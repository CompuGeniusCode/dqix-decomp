#include "System/Matrix.h"
#include <globaldefs.h>

// USA: func_020c6914  (semantic: GX_SendFifo48B)
//
// PROVENANCE: SonicRushAdventure-Decomp/lib/NitroSDK/src/gx/gxasm.c -- GX_SendFifo48B.
// Dest has no writeback across the 4 blocks (fixed FIFO port), distinguishing it from the
// otherwise-identical MI_Copy48B (stmia r1!, real memcpy) in the same reference tree.
// C attempted twice: (1) 12-byte struct aggregate assignment -- mwcc calls an outlined
// copy helper (`bl`), not inline ldm/stm, wrong shape; (2) field-by-field copy -- mwcc
// emits one ldr/str per word, never ldm/stm, wrong shape. Same register-block tell as
// Mat4x4_WriteIdentity/Mat4x4_ConvertTo4x3/_Z20WriteGXFifoZeroBurstPVv: this codebase's mwcc config never batches
// straight-line loads/stores into ldm/stm from C source.
extern "C" ARM asm void func_020c6914(const void *pSrc, void *pDest) {
    ldmia r0!, {r2, r3, r12}
    stmia r1, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1, {r2, r3, r12}
    bx lr
}
