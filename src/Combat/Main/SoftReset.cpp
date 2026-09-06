#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_0200078c
//
// PROVENANCE: pokediamond/arm9/lib/syscall/secure.s -- SVC_SoftReset identity/BIOS
// secure-area idiom (swi 0; bx lr), same trampoline family as VBlankIntrWait.cpp (SVC_VBlankIntrWait).
extern "C" THUMB asm void SoftReset(void)
{
    swi 0
    bx lr
}
