#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_020c56dc
//
// PROVENANCE: pokediamond/arm9/lib/NitroSDK/src/GX_g3x.c -- GXi_NopClearFifo128_. Also asm
// in sm64ds-decomp (func_020553c0) with the same tell noted there: no compiler emits 32
// identical non-writeback stm stores to a single fixed address (a hardware FIFO command
// port, not memory) -- and mwcc on this codebase never batches even ordinary sequential
// field stores into stm at all (confirmed against func_020c21dc/func_020c2208: field
// writes always came out as individual str). C attempted (32x manually-unrolled
// volatile-struct field zeroing at the same fixed pointer): mwcc emitted one str per
// word, no stm, wrong shape -- BYTEDIFF.
// The parameter is `volatile`, and that is not cosmetic: symbols.txt binds
// _Z20WriteGXFifoZeroBurstPVv, and the V is the volatile qualifier. Declaring plain `void *`
// mangles to _Z20WriteGXFifoZeroBurstPv and link-fails on the missing symbol.
ARM asm void WriteGXFifoZeroBurst(void volatile *reg) {
    mov r1, #0
    mov r2, #0
    mov r3, #0
    mov r12, #0
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    stmia r0, {r1, r2, r3, r12}
    bx lr
}
