#include <globaldefs.h>

unsigned int DisableInterrupts();
unsigned int RestoreInterrupts(unsigned int mask);

// USA: func_020c9ec4
ARM void WaitDmaIdleAndResetChannel0(int channel) {
    asm {
        mov r4, r0
        bl DisableInterrupts
        add r1, r4, r4, lsl #1
        add r1, r1, #2
        mov r1, r1, lsl #2
        add r1, r1, #0xb0
        add r2, r1, #0x4000000
    _poll:
        ldr r1, [r2, #0]
        tst r1, #0x80000000
        bne _poll
        cmp r4, #0
        bne _skip
        mov r1, #0xc
        mul r2, r4, r1
        add r1, r2, #0xb0
        add r2, r2, #0x4000000
        mov r3, #0
        str r3, [r2, #0xb0]
        add r2, r1, #0x4000000
        ldr r1, =0x81400001
        str r3, [r2, #4]
        str r1, [r2, #8]
    _skip:
        bl RestoreInterrupts
    }
}
