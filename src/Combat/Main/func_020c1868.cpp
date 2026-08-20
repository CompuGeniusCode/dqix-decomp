#include <globaldefs.h>

// USA: func_020c1868  (semantic: MTX_Copy43To44_)
//
// PROVENANCE: SonicRushAdventure-Decomp/lib/NitroSDK/src/fx/fx_mtx43.c — MTX_Copy43To44_. NitroSDK
// fixed-point 4x3-to-4x4 matrix widen (appends the constant homogeneous column), byte-identical asm.
extern "C" ARM
asm void func_020c1868(register const void* pSrc, register void* pDst)
{
    stmfd sp!, {r4}

    mov   r12, #0x0000
    ldmia r0!, {r2-r4}
    stmia r1!, {r2-r4, r12}
    ldmia r0!, {r2-r4}
    stmia r1!, {r2-r4, r12}
    ldmia r0!, {r2-r4}
    stmia r1!, {r2-r4, r12}
    mov   r12, #0x1000
    ldmia r0!, {r2-r4}
    stmia r1!, {r2-r4, r12}

    ldmfd sp!, {r4}
    bx    lr
}
