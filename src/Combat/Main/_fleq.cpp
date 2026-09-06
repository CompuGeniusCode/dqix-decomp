#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_0200c020
//
// PROVENANCE: pokediamond/arm9/asm/RUNTIME_f_cmp.s — _fleq. MSL runtime float less-or-equal compare.
extern "C" ARM asm int _fleq(float a, float b) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo L_af9c
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movle r0, #1
    movgt r0, #0
    mrs ip, cpsr
    orrgt ip, ip, #0x20000000
    bicgt ip, ip, #0x40000000
    bicle ip, ip, #0x20000000
    orrle ip, ip, #0x40000000
    msr cpsr_f, ip
    bx lr
L_af9c:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x40000000
    orr ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
}
