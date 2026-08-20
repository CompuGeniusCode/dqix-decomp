#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_0200062c
//
// PROVENANCE: BIOS secure-area syscall trampoline (swi 0x13; bx lr), same family as
// Halt.cpp/IntrWait.cpp (SVC_Halt, SVC_WaitIntr) -- bare swi-then-bx, no register setup.
extern "C" THUMB asm int HuffUnCompReadByCallback(void* source, void* dest, void* callback)
{
    swi 0x13
    bx lr
}
