#include <globaldefs.h>

// USA: func_020c1840  (semantic: MTX_Identity43_)
//
// PROVENANCE: SonicRushAdventure-Decomp/lib/NitroSDK/src/fx/fx_mtx43.c — MTX_Identity43_. NitroSDK
// fixed-point 4x3 identity matrix store, byte-identical asm.
extern "C" ARM
asm void func_020c1840(register void* pDst)
{
    mov  r2, #0x1000
    mov  r3, #0
    stmia r0!, {r2, r3}
    mov  r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}

    bx    lr
}
