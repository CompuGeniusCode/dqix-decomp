#include <globaldefs.h>

extern "C" void func_ov028_021d8c20(void* obj);

// USA: func_ov028_021d94e4
ARM void ResetFields_021d94e4(void* obj) {
    asm {
        mov ip, #0x0
        strb ip, [r0, #0x9c]
        str ip, [r0, #0x98]
        str ip, [r0, #0x94]
        str ip, [r0, #0x8c]
        str ip, [r0, #0x90]
        add r2, r0, #0x8c
        add r1, r0, #0x84
        ldmia r2, {r2, r3}
        stmia r1, {r2, r3}
        str ip, [r0, #0xa8]
        str ip, [r0, #0xac]
        add r2, r0, #0xa8
        add r1, r0, #0xa0
        ldmia r2, {r2, r3}
        stmia r1, {r2, r3}
        bl func_ov028_021d8c20
    }
}
