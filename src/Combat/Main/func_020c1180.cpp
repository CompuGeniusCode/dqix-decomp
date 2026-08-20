#include <globaldefs.h>

// USA: func_020c1180  (semantic: MTX_Identity33_)
//
// PROVENANCE: SonicRushAdventure-Decomp/lib/NitroSDK/src/fx/fx_mtx33.c — MTX_Identity33_. NitroSDK
// fixed-point 3x3 identity matrix store, byte-identical asm.
extern "C" ARM
asm void func_020c1180(register void* pDst)
{
    mov  r2, #0x1000
    str  r2, [r0, #32]
    mov  r3, #0
    stmia r0!, {r2, r3}
    mov  r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    bx   lr
}
