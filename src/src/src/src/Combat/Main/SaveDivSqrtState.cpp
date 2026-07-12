#include <globaldefs.h>

// USA: func_020cd594
ARM asm void SaveDivSqrtState(void* dst) {
    ldr r1, =0x4000290
    stmdb sp!, {r4}
    ldmia r1, {r2, r3, r4, ip}
    stmia r0!, {r2, r3, r4, ip}
    ldrh ip, [r1, #-0x10]
    add r1, r1, #0x28
    ldmia r1, {r2, r3}
    stmia r0!, {r2, r3}
    and ip, ip, #0x3
    ldrh r2, [r1, #-0x8]
    strh ip, [r0, #0x0]
    and r2, r2, #0x1
    strh r2, [r0, #0x2]
    ldmia sp!, {r4}
    bx lr
}
