#include <globaldefs.h>

ARM unsigned int EnableSpecificInterrupts(unsigned int mask);

extern char data_021112ac;
extern char data_021112b0;
extern char data_021112b4;

// USA: func_020c6c48
ARM void RegisterTimerIrqHandler(int index, unsigned int a1, unsigned int a2) {
    asm {
        mov r3, 0xc
        mul r4, r0, r3
        ldr ip, =data_021112ac
        add r0, r0, 0x3
        mov r3, 1
        mov r0, r3, lsl r0
        ldr r3, =data_021112b4
        str r1, [ip, r4]
        str r2, [r3, r4]
        bl EnableSpecificInterrupts
        ldr r0, =data_021112b0
        mov r1, 1
        str r1, [r0, r4]
    }
}
