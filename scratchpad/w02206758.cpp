#include <globaldefs.h>
#include "System/Memory.h"

struct SplitRingStruct02206758 {
    char pad[0x10];
    char* buf1;
    int cap1;
    char* buf2;
    int cap2;
};

// USA: func_ov031_02206758
extern "C" ARM int DrainSplitRingBuffer_02206758(char* dst, int len, SplitRingStruct02206758* ctx) {
    int n1 = ctx->cap1;
    int n2 = ctx->cap2;
    if (n1 > len) {
        n1 = len;
        n2 = 0;
    } else {
        int rem = len - n1;
        if (n2 > rem) n2 = rem;
    }
    if (n1 > 0) {
        VectorizedInvertedMemcpy(ctx->buf1, dst, n1);
        ctx->buf1 += n1;
        ctx->cap1 -= n1;
    }
    if (n2 > 0) {
        VectorizedInvertedMemcpy(ctx->buf2, dst + n1, n2);
        ctx->buf2 += n2;
        ctx->cap2 -= n2;
    }
    return n1 + n2;
}
