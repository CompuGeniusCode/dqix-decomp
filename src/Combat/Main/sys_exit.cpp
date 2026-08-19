#include <globaldefs.h>

// USA: func_0200d8bc  (semantic: sys_exit)
//
// PROVENANCE: sm64ds-decomp/src/func_0207199c.c -- `asm void`, hand-written source.
// A semihosting call (`swi 0x123456`) cannot be expressed in C at all, which is the tell here.
// SonicRushAdventure carries the same routine only as a splitter dump in lib/asm/ARM9/msl.s;
// that is un-decompiled leftover and is not evidence.
// MSL runtime process-exit syscall wrapper.

extern "C" ARM asm void func_0200d8bc(int status) {
    mov r1, #0
    mov r0, #0x18
    swi 0x123456
    mov pc, lr
}
