#include <globaldefs.h>

// KEEP-NAME: the ROM symbol is a curated name, not a func_ tag.
// USA: func_020004ec
//
// PROVENANCE: pokediamond/arm9/lib/syscall/secure.s -- SVC_WaitIntr identity/BIOS
// secure-area idiom (swi 4; bx lr). Every reference project's SVC_WaitIntr also carries a
// leading `mov r2, #0` that this build's trampoline does not; the bare swi-then-bx shape
// it does share is the exact family every other stub in this table (SVC_WaitByLoop,
// SVC_Halt, SVC_Div, ...) already ties on byte-for-byte, so the swi immediate below is
// the only free variable, fixed to match this ROM's instruction.
extern "C" THUMB asm void IntrWait(int waitFlag, int flags)
{
    swi 4
    bx lr
}
