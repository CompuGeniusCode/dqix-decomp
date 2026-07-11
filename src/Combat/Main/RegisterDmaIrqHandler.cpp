#include <globaldefs.h>

ARM unsigned int EnableInterruptBits(unsigned int mask);

extern char data_0211127c;
extern char data_02111280;
extern char data_02111284;

// USA: func_020c6c00
ARM void RegisterDmaIrqHandler(int index, unsigned int a1, unsigned int a2) {
    asm {
        mov r3, 0xc
        mul r6, r0, r3
        ldr ip, =data_0211127c
        add r4, r0, 0x8
        mov r5, 1
        mov r0, r5, lsl r4
        ldr r3, =data_02111284
        str r1, [ip, r6]
        str r2, [r3, r6]
        bl EnableInterruptBits
        and r1, r0, r5, lsl r4
        ldr r0, =data_02111280
        str r1, [r0, r6]
    }
}
