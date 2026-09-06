#include <globaldefs.h>

// USA: func_0200bd10
//
// PROVENANCE: pokediamond/arm9/asm/RUNTIME_f_cmp.s — _dleq. MSL runtime double less-or-equal compare.
extern "C" ARM asm int func_0200bd10(double a, double b) {
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_acbc
    cmn ip, r3, lsl #1
    bhs L_acd0
L_ac50:
    orrs ip, r3, r1
    bmi L_ac84
    cmp r1, r3
    cmpeq r0, r2
    movls r0, #1
    movhi r0, #0
    bx lr
L_ac6c:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    orr ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
L_ac84:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    bne L_aca8
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    orr ip, ip, #0x40000000
    msr cpsr_f, ip
    bxeq lr
L_aca8:
    cmp r3, r1
    cmpeq r2, r0
    movls r0, #1
    movhi r0, #0
    bx lr
L_acbc:
    bne L_ac6c
    cmp r0, #0
    bhi L_ac6c
    cmn ip, r3, lsl #1
    blo L_ac50
L_acd0:
    bne L_ac6c
    cmp r2, #0
    bhi L_ac6c
    b L_ac50
}
