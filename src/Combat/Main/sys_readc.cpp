#include <globaldefs.h>

// USA: func_0200d8a8  (semantic: sys_readc)
//
// PROVENANCE: same MSL runtime semihosting family as sys_exit.cpp (func_0200d8bc), 0x14
// bytes away in ROM. Operation number r0=7 is ARM semihosting SYS_READC (read one
// character from the debug console); r1 is unused and always zeroed.
// A semihosting call (`swi 0x123456`) cannot be expressed in C at all, which is the tell here.

extern "C" ARM asm int func_0200d8a8(void) {
    str lr, [sp, #-4]!
    mov r1, #0
    mov r0, #7
    swi 0x123456
    ldr pc, [sp], #4
}
