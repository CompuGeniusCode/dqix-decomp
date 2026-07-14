#include <globaldefs.h>

// USA: func_02088474
ARM asm void ResetTargetFlags02088474(void* obj, int bits, int id) {
    mov ip, #0
    strb ip, [r0, #0x21]
    ldr r3, [r0, #0x18]
    cmp r2, #0x1fc
    bic r3, r3, #0x20
    str r3, [r0, #0x18]
    ldr r3, [r0, #0x14]
    mov r1, r1, lsl #28
    bic r3, r3, #0x80000
    str r3, [r0, #0x14]
    ldrh r3, [r0, #0x22]
    bic r3, r3, #0x3c
    strh r3, [r0, #0x22]
    ldr r3, [r0, #0x14]
    bic r3, r3, #0x800000
    str r3, [r0, #0x14]
    ldrne r3, =0x20f
    strb ip, [r0, #0x24]
    cmpne r2, r3
    ldreq r3, [r0, #0x14]
    moveq r2, #0
    biceq r3, r3, #0x1000000
    streq r3, [r0, #0x14]
    streqb r2, [r0, #0x24]
    ldr r2, [r0, #0x14]
    orr r2, r2, #0x80000
    str r2, [r0, #0x14]
    ldrh r2, [r0, #0x22]
    bic r2, r2, #0x3c
    orr r1, r2, r1, lsr #26
    strh r1, [r0, #0x22]
    bx lr
}
