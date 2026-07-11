#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
extern "C" void func_020c7898(int);

extern char data_021118e0;

// USA: func_020d0f74
ARM asm void PumpUntilField0x114Bit8Forever(void) {
        stmdb sp!, {r4, r5, r6, lr}
        ldr r5, =data_021118e0
        mov r4, #0
loop_top:
        bl DisableInterrupts
        ldr r1, [r5, #0x114]
        mov r6, r0
        tst r1, #8
        bne restore_and_notify
inner_loop:
        mov r0, r4
        bl func_020c7898
        ldr r0, [r5, #0x114]
        tst r0, #8
        beq inner_loop
restore_and_notify:
        mov r0, r6
        bl RestoreInterrupts
        ldr r1, [r5, #0x40]
        mov r0, r5
        blx r1
        b loop_top
}
