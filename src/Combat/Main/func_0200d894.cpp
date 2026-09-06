#include <globaldefs.h>

// USA: func_0200d894  (semantic: sys_write0)
//
// PROVENANCE: same MSL runtime semihosting family as sys_exit.cpp (func_0200d8bc) and
// sys_readc.cpp (func_0200d8a8). Operation number r0=3 is ARM semihosting SYS_WRITE0
// (write a null-terminated string to the debug console); r1 is the string pointer,
// passed through from the incoming r0.
// A semihosting call (`swi 0x123456`) cannot be expressed in C at all, which is the tell here.

extern "C" ARM asm void func_0200d894(const char* s) {
    str lr, [sp, #-4]!
    mov r1, r0
    mov r0, #3
    swi 0x123456
    ldr pc, [sp], #4
}
