#include <globaldefs.h>

// USA: func_0200bedc
//
// PROVENANCE: pokediamond/arm9/asm/RUNTIME_f_cmp.s — _dneq. MSL runtime double not-equal compare.
extern "C" ARM asm int func_0200bedc(double a, double b) {
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_ae70
    cmn ip, r3, lsl #1
    bhs L_ae84
L_ae1c:
    orrs ip, r3, r1
    bmi L_ae4c
    cmp r1, r3
    cmpeq r0, r2
    movne r0, #1
    moveq r0, #0
    bx lr
L_ae38:
    mov r0, #1
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_f, ip
    bx lr
L_ae4c:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movne r0, #1
    moveq r0, #0
    bx lr
L_ae70:
    bne L_ae38
    cmp r0, #0
    bhi L_ae38
    cmn ip, r3, lsl #1
    blo L_ae1c
L_ae84:
    bne L_ae38
    cmp r2, #0
    bhi L_ae38
    b L_ae1c
}
