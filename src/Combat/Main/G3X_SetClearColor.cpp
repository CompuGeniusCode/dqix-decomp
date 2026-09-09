#include <globaldefs.h>

struct ClearColorReg5588 {
    volatile unsigned int color;    /* 0x00  CLEAR_COLOR */
    volatile unsigned short depth;  /* 0x04  CLEAR_DEPTH */
};

// Writes the 3D engine's clear colour and clear depth. 0x04000350 takes the RGB555 colour in bits
// 0-14, fog enable in bit 15, alpha in bits 16-20 and the clear polygon id in bits 24-29; the
// halfword at 0x04000354 takes the depth. The argument order and the packing are exactly Nitro's
// G3X_SetClearColor(color, alpha, depth, polygonID, fog), so this seems to be the SDK call left
// out of line rather than a wrapper the game wrote itself.
extern "C" ARM void G3X_SetClearColor(int color, int alpha, int depth, int polygonId, int fogEnable) {
    struct ClearColorReg5588* reg = (struct ClearColorReg5588*)0x4000350;
    unsigned int value = color | (alpha << 16) | (polygonId << 24);
    if (fogEnable) value |= 0x8000;
    reg->color = value;
    reg->depth = depth;
}
