#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_0200c088
//
// PROVENANCE: SonicRushAdventure-Decomp/lib/asm/ARM9/msl.s — _fls. MSL runtime float less-than compare.
extern "C" ARM asm int _fls(float a, float b) {
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo L_a340
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movlt r0, #1
    movge r0, #0
    mrs ip, cpsr
    orrge ip, ip, #0x20000000
    biclt ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
L_a340:
    mov r0, #0
    mrs ip, cpsr
    orr ip, ip, #0x20000000
    msr cpsr_f, ip
    bx lr
}
