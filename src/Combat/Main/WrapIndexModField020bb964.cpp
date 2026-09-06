#include <globaldefs.h>

struct WrapCtx020bb964 {
    int unk_0;
    unsigned int modulus;
};

// USA: func_020bb964
ARM unsigned short WrapIndexModField020bb964(WrapCtx020bb964* ctx, unsigned int value) {
    return (unsigned short)((value + 1) % ctx->modulus);
}
