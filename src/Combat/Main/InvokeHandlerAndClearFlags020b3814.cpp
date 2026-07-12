#include <globaldefs.h>

extern char data_0210a010;

extern "C" void func_020b6acc(unsigned int a, void* b, int n);

// USA: func_020b3814
// Two loads of &data_0210a010 are intentional: the real build reloads the
// base pointer after the call (r0/r1 are caller-saved) and keeps the two
// pre-call address materializations as separate literal-pool words rather
// than folding the +4 into one relocation or fusing into a post-indexed
// load, so this is hand-written to reproduce that exact layout.
ARM asm void InvokeHandlerAndClearFlags020b3814(void) {
    stmdb sp!, {r3, lr}
    ldr r0, [pc, #0x28]
    ldr r1, [pc, #0x28]
    ldr r0, [r0, #0x0]
    add r1, r1, #0x4
    mov r2, #0x3e
    bl func_020b6acc
    ldr r0, [pc, #0x10]
    ldr r1, [r0, #0xfc]
    bic r1, r1, #0x1
    bic r1, r1, #0x2
    str r1, [r0, #0xfc]
    ldmia sp!, {r3, pc}
poolA:
    DCD data_0210a010
poolB:
    DCD data_0210a010
}
