#include <globaldefs.h>

// USA: func_0200be50
//
// PROVENANCE: pokediamond/arm9/asm/RUNTIME_f_cmp.s — _deq. MSL runtime double equal compare.
extern "C" ARM asm int func_0200be50(double a, double b) {
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_ade4
    cmn ip, r3, lsl #1
    bhs L_adf8
L_ad90:
    orrs ip, r3, r1
    bmi L_adc0
    cmp r1, r3
    cmpeq r0, r2
    moveq r0, #1
    movne r0, #0
    bx lr
L_adac:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    msr cpsr_f, ip
    bx lr
L_adc0:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    moveq r0, #1
    movne r0, #0
    bx lr
L_ade4:
    bne L_adac
    cmp r0, #0
    bhi L_adac
    cmn ip, r3, lsl #1
    blo L_ad90
L_adf8:
    bne L_adac
    cmp r2, #0
    bhi L_adac
    b L_ad90
}
