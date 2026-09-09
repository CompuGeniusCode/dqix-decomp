#include <globaldefs.h>

// USA: func_020001c0
// from pokediamond/arm9/lib/syscall/secure.s -- SVC_CpuSet. BIOS secure-area syscall
// trampoline (swi 0xb; bx lr), byte-identical to the reference.
extern "C" THUMB asm void CpuSet(const void *src, void *dst, int size)
{
    swi 0xb
    bx lr
}
