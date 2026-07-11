#include <globaldefs.h>

unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);
extern "C" void func_020c7a90(void*, int);

extern char data_021118e0;

// USA: func_020cffcc
ARM asm int SwapField0x108AndNotify(int val) {
        stmdb sp!, {r3, r4, r5, r6, r7, lr}
        ldr r5, =data_021118e0
        mov r7, r0
        bl DisableInterrupts
        ldr r6, [r5, #0x108]
        mov r4, r0
        mov r1, r7
        add r0, r5, #0x44
        str r7, [r5, #0x108]
        bl func_020c7a90
        mov r0, r4
        bl RestoreInterrupts
        mov r0, r6
        ldmia sp!, {r3, r4, r5, r6, r7, pc}
}
