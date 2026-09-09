#include <globaldefs.h>

// NitroSDK's halfword copy loop, from pokeheartgold/lib/NitroSDK/asm/mi_memory.s, kept as inline
// asm because it is hand-written rather than compiler output. Size is a byte count stepped by two
// and the compare is signed, so a size with the top bit set copies nothing.
// The out-of-line symbol is the MIi_ one: SonicRushAdventure-Decomp's nitro/mi/memory.h declares
// MIi_CpuCopy16(const void *srcp, void *destp, u32 size) and makes MI_CpuCopy16 an SDK_INLINE
// wrapper around it.
extern "C" ARM asm void MIi_CpuCopy16(const unsigned short* src, unsigned short* dst, unsigned int size) {
    mov ip, #0
top:
    cmp ip, r2
    blt load
    b after_load
load:
    ldrh r3, [r0, ip]
after_load:
    blt store
    b after_store
store:
    strh r3, [r1, ip]
after_store:
    blt incr
    b after_incr
incr:
    add ip, ip, #2
after_incr:
    blt top
    bx lr
}
