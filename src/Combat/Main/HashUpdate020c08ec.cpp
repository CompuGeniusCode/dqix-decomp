#include <globaldefs.h>
#include "System/Memory.h"

struct HashCtx020c08ec {
    unsigned int unk0[5];
    unsigned int totalLo;
    unsigned int totalHi;
    unsigned int index;
    unsigned char buffer[0x40];
};

typedef void (*HashTransformFn020c08ec)(HashCtx020c08ec*, const void*, unsigned int);
extern HashTransformFn020c08ec data_020f2154;

// USA: func_020c08ec
ARM void HashUpdate020c08ec(HashCtx020c08ec* ctx, const unsigned char* src, unsigned int len) {
    unsigned char* buf = ctx->buffer;
    if (len == 0) {
        return;
    }

    unsigned int old = ctx->totalLo;
    unsigned int newLo = old + (len << 3);
    if (newLo < old) {
        ctx->totalHi = ctx->totalHi + 1;
    }
    ctx->totalHi = ctx->totalHi + (len >> 0x1d);
    ctx->totalLo = newLo;

    unsigned int index = ctx->index;
    if (index != 0) {
        if (index + len >= 0x40) {
            unsigned int fill = 0x40 - index;
            VectorizedInvertedMemcpy(src, buf + index, fill);
            len -= fill;
            src += fill;
            data_020f2154(ctx, buf, 0x40);
            ctx->index = 0;
        } else {
            VectorizedInvertedMemcpy(src, buf + index, len);
            ctx->index = ctx->index + len;
            return;
        }
    }

    if (len >= 0x40) {
        int blockLen = len & ~0x3f;
        len -= blockLen;
        if (((unsigned int)src & 0x3) == 0) {
            data_020f2154(ctx, src, blockLen);
            src += blockLen;
        } else {
            do {
                VectorizedInvertedMemcpy(src, buf, 0x40);
                src += 0x40;
                data_020f2154(ctx, buf, 0x40);
                blockLen -= 0x40;
            } while (blockLen > 0);
        }
    }

    ctx->index = len;
    if (len == 0) {
        return;
    }
    VectorizedInvertedMemcpy(src, buf, len);
}
