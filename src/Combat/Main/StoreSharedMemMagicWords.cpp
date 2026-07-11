#include <globaldefs.h>

extern char data_027e0000;

// USA: func_020c6d48
ARM void StoreSharedMemMagicWords(void) {
    asm {
        ldr ip, =data_027e0000
        ldr r3, =0xfddb597d
        add r0, ip, #0x3000
        ldr r2, =0x7bf9dd5b
        ldr r1, =0x400
        str r3, [r0, #0xf7c]
        add r0, ip, #0x3f80
        str r2, [r0, -r1]
    }
}
