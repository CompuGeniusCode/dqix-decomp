#include <globaldefs.h>

// NitroSDK's word-granularity copy, matched instruction for instruction against MIi_CpuCopy32 in
// the reference NDS decomps (mi_memory.s). Arguments are (src, dest, byte count); the count is
// expected to be a multiple of four, and there is no alignment check and no overlap handling, so
// this is not a memmove. It is a raw NitroSDK .s routine, ported here as mwcc inline asm.
extern "C" ARM asm void MIi_CpuCopy32(const unsigned int* src, unsigned int* dst, unsigned int size) {
    add ip, r1, r2
top:
    cmp r1, ip
    blt load
    b after_load
load:
    ldmia r0!, {r2}
after_load:
    blt store
    b after_store
store:
    stmia r1!, {r2}
after_store:
    blt top
    bx lr
}
