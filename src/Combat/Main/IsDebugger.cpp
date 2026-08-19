#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_020000d4
//
// PROVENANCE: pokediamond/arm9/lib/syscall/secure.s -- SVC_IsDebugger. BIOS secure-area
// syscall trampoline (swi 0xf; bx lr), byte-identical to the reference.
extern "C" THUMB asm int IsDebugger(void)
{
    swi 0xf
    bx lr
}
