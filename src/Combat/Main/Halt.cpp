#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_0200056c
//
// PROVENANCE: pokediamond/arm9/lib/syscall/secure.s -- SVC_Halt. BIOS secure-area syscall
// trampoline (swi 6; bx lr), byte-identical to the reference.
extern "C" THUMB asm void Halt(void)
{
    swi 6
    bx lr
}
