#include <globaldefs.h>

// USA: func_020c8b44
// PROVENANCE: pokediamond/arm9/lib/NitroSDK/src/OS_exception.c — OSi_SetExContext (also
// pokeheartgold/pokeblack/SonicRushAdventure-Decomp under the same name). Copies the trapped
// register state out of the exception frame into a static OSExceptionContext, switching CPU
// mode via cpsr/spsr to reach the banked sp/lr of the faulting mode.
extern char data_021115b4;

extern "C" ARM asm void func_020c8b44(void* exinfo) {
    ldr r1, =data_021115b4
    mrs r2, cpsr
    str r2, [r1, #0x74]
    str r0, [r1, #0x6c]
    ldr r0, [r12]
    str r0, [r1, #4]
    ldr r0, [r12, #4]
    str r0, [r1, #8]
    ldr r0, [r12, #8]
    str r0, [r1, #0xc]
    ldr r0, [r12, #0xc]
    str r0, [r1, #0x10]
    ldr r2, [r12, #0x10]
    bic r2, r2, #1
    add r0, r1, #0x14
    stmia r0, {r4-r11}
    str r12, [r1, #0x70]
    ldr r0, [r2]
    str r0, [r1, #0x64]
    ldr r3, [r2, #4]
    str r3, [r1]
    ldr r0, [r2, #8]
    str r0, [r1, #0x34]
    ldr r0, [r2, #0xc]
    str r0, [r1, #0x40]
    mrs r0, cpsr
    orr r3, r3, #0x80
    bic r3, r3, #0x20
    msr cpsr_fsxc, r3
    str sp, [r1, #0x38]
    str lr, [r1, #0x3c]
    mrs r2, spsr
    str r2, [r1, #0x7c]
    msr cpsr_fsxc, r0
    bx lr
}
