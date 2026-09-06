#include <globaldefs.h>

// USA: func_0200bc78
//
// PROVENANCE: pokediamond/arm9/asm/RUNTIME_f_cmp.s — _dgr. MSL runtime double greater-than compare.
extern "C" ARM asm int func_0200bc78(double a, double b) {
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs L_ac18
    cmn ip, r3, lsl #1
    bhs L_ac2c
L_abb8:
    orrs ip, r3, r1
    bmi L_abe8
    cmp r1, r3
    cmpeq r0, r2
    movhi r0, #1
    movls r0, #0
    bx lr
L_abd4:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
L_abe8:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_f, ip
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movhi r0, #1
    movls r0, #0
    bx lr
L_ac18:
    bne L_abd4
    cmp r0, #0
    bhi L_abd4
    cmn ip, r3, lsl #1
    blo L_abb8
L_ac2c:
    bne L_abd4
    cmp r2, #0
    bhi L_abd4
    b L_abb8
}
