#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_020002cc
//
// PROVENANCE: pokediamond/arm9/lib/syscall/secure.s -- SVC_LZ77UnCompReadByCallbackWrite16bit
// identity/BIOS secure-area idiom (swi 0x12; bx lr), same trampoline family as VBlankIntrWait.cpp.
extern "C" THUMB asm void LZ77UnCompReadByCallbackWrite16bit(void)
{
    swi 0x12
    bx lr
}
