#include <globaldefs.h>

// USA: func_020c21dc
// Writes a fixed 64-byte block: word 0x1000 at offsets 0x0,0x14,0x28,0x3c, zero elsewhere.
ARM void InitStruct020c21dc(void* buf) {
    asm {
        mov r2, #0x1000
        mov r3, #0
        stmia r0!, {r2, r3}
        mov r1, #0
        stmia r0!, {r1, r3}
        stmia r0!, {r1, r2, r3}
        stmia r0!, {r1, r3}
        stmia r0!, {r1, r2, r3}
        stmia r0!, {r1, r3}
        stmia r0!, {r1, r2}
    }
}
