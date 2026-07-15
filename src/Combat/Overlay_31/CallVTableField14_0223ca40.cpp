#include <globaldefs.h>

// USA: func_ov031_0223ca40
extern "C" ARM asm void CallVTableField14_0223ca40(void *obj) {
    stmdb sp!, {r3, lr}
    ldr r2, [r0, #0x14]
    ldr r2, [r2, #0x4]
    blx r2
    ldmia sp!, {r3, pc}
}
