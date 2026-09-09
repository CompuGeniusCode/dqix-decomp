#include <globaldefs.h>

// NitroSDK's halfword fill worker, which MI_CpuFill16 and MI_CpuClear16 both call, hence the
// (data, dest, byte count) argument order rather than dest first; the SDK's own text is in
// pokeheartgold/lib/NitroSDK/asm/mi_memory.s. The ROM's form is one cmp and three blt/b pairs
// around a plain strh and a plain add, with no conditional execution anywhere, which is why this
// file keeps labelled assembly instead of a predicated loop. 25 call sites, spread over main,
// ov027 and ov031.
extern "C" ARM asm void MIi_CpuClear16(unsigned short value, unsigned short* dst, unsigned int size) {
    mov r3, #0
top:
    cmp r3, r2
    blt store
    b after_store
store:
    strh r0, [r1, r3]
after_store:
    blt incr
    b after_incr
incr:
    add r3, r3, #2
after_incr:
    blt top
    bx lr
}
