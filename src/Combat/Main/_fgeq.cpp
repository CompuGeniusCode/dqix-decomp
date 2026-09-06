#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_0200bf68
//
// PROVENANCE: pokediamond/arm9/asm/RUNTIME_f_cmp.s — _fgeq. MSL runtime float greater-or-equal compare.
extern "C" ARM asm int _fgeq(float a, float b) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmpcs r3, r1, lsl #1
    blo L_aedc
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movge r0, #1
    movlt r0, #0
    mrs ip, cpsr
    biclt ip, ip, #0x20000000
    orrge ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
L_aedc:
    mov r0, #0
    mrs ip, cpsr
    bic ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
}
