#include <globaldefs.h>
#include "System/Memory.h"

struct HashCtx_0220b8f4 {
    unsigned char pad[0x14];
    unsigned int countHi;
    unsigned int countLo;
    unsigned char buffer[0x40];
};

extern "C" void func_ov031_0220b218(HashCtx_0220b8f4*, const void*);

// USA: func_ov031_0220b8f4
extern "C" ARM void HashUpdateBlock_0220b8f4(HashCtx_0220b8f4* ctx, const void* input, unsigned int inputLen) {
    unsigned int i, index, partLen;
    index = (ctx->countLo >> 3) & 0x3f;
    if ((ctx->countLo += (inputLen << 3)) < (inputLen << 3)) ctx->countHi++;
    ctx->countHi += (inputLen >> 29);
    partLen = 0x40 - index;
    if (inputLen >= partLen) {
        VectorizedInvertedMemcpy(input, ctx->buffer + index, partLen);
        index = 0;
        func_ov031_0220b218(ctx, ctx->buffer);
        i = partLen;
        if (i + 0x3f < inputLen) {
            do {
                func_ov031_0220b218(ctx, (char*)input + i);
                i += 0x40;
            } while (i + 0x3f < inputLen);
        }
    } else {
        i = 0;
    }
    VectorizedInvertedMemcpy((char*)input + i, ctx->buffer + index, inputLen - i);
}
