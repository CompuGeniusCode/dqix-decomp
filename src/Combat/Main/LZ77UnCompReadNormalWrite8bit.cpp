#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_02000140
//
// PROVENANCE: pokediamond/arm9/lib/syscall/secure.s -- SVC_LZ77UnCompReadNormalWrite8bit BIOS
// secure-area syscall trampoline (swi 0x11; bx lr), same stub family as RLUnCompReadNormalWrite8bit.cpp.
extern "C" THUMB asm void LZ77UnCompReadNormalWrite8bit(const void* src, void* dst)
{
    swi 0x11
    bx lr
}
