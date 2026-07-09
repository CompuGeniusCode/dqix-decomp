#include <globaldefs.h>

// USA: func_020c8348
ARM void WaitForVCountZero(void) {
    asm {
        mov ip, 0x4000000
        ldr r1, [ip, 0x208]
        str ip, [ip, 0x208]
    _wait:
        ldrh r0, [ip, 0x6]
        cmp r0, 0
        bne _wait
        str r1, [ip, 0x208]
    }
}
