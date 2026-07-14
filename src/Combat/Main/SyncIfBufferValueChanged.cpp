#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
void DispatchType0x11InitOnce(int, int);

// USA: func_020d1234
ARM asm void SyncIfBufferValueChanged(unsigned int newVal) {
        stmdb sp!, {r3, r4, lr}
        sub sp, sp, #4
        ldr r2, =0x027ffc10
        ldrh r1, [r2, #0]
        cmp r1, #0
        subeq r1, r2, #0x410
        subne r1, r2, #0x10
        ldr r1, [r1, #0]
        str r1, [sp, #0]
        ldr r1, [sp, #0]
        cmp r0, r1
        addeq sp, sp, #4
        ldmeqia sp!, {r3, r4, pc}
        bl DisableIRQInterrupts
        mov r4, r0
        mov r0, #0xe
        mov r1, #0x11
        mov r2, #0
        bl DispatchType0x11InitOnce
        mov r0, r4
        bl SetIRQInterruptState
        add sp, sp, #4
        ldmia sp!, {r3, r4, pc}
}
