#include <globaldefs.h>

// USA: func_0208b548
// Packs the GX TEXIMAGE_PARAM register (0x040004A8):
//   (fmt << 26) | (addr >> 3) | (coord << 30) | (sizeS << 20) | (sizeT << 23) |
//   (repeat << 16) | (flip << 18) | (color0 << 29)
// Written in asm so the leaf keeps lr for its return (mwcc otherwise spills a
// register to prefetch a stacked argument, cf. the sibling GX register writers).
ARM void WriteTexImageParam0208b548(int fmt, int coord, int sizeS, int sizeT,
                                    int repeat, int flip, int color0, unsigned int addr) {
    asm {
        ldr ip, [sp, #0xc]
        mov r0, r0, lsl #0x1a
        orr r0, r0, ip, lsr #0x3
        orr r0, r0, r1, lsl #0x1e
        orr r0, r0, r2, lsl #0x14
        ldr r1, [sp, #0x0]
        orr r0, r0, r3, lsl #0x17
        ldr r2, [sp, #0x4]
        orr r0, r0, r1, lsl #0x10
        ldr r3, [sp, #0x8]
        orr r1, r0, r2, lsl #0x12
        ldr r0, =0x40004a8
        orr r1, r1, r3, lsl #0x1d
        str r1, [r0, #0x0]
    }
}
