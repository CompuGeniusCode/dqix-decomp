#include <globaldefs.h>
#include "System/Memory.h"

struct TwoRegionCtx02206758 {
    char pad[0x10];
    char* destA;
    int capA;
    char* destB;
    int capB;
};

// USA: func_ov031_02206758  (semantic: CopyIntoTwoRegions_02206758)
extern "C" ARM int func_ov031_02206758(char* src, int maxLen, TwoRegionCtx02206758* ctx) {
    int capA = ctx->capA;
    int capB = ctx->capB;
    if (capA > maxLen) {
        capA = maxLen;
        capB = 0;
    } else {
        int leftover = maxLen - capA;
        if (capB > leftover) {
            capB = leftover;
        }
    }
    if (capA > 0) {
        VectorizedInvertedMemcpy(ctx->destA, src, capA);
        ctx->destA += capA;
        ctx->capA -= capA;
    }
    if (capB > 0) {
        VectorizedInvertedMemcpy(ctx->destB, src + capA, capB);
        ctx->destB += capB;
        ctx->capB -= capB;
    }
    return capA + capB;
}
