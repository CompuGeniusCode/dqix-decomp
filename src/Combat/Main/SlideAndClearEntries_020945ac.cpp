#include <globaldefs.h>

extern "C" void VectorizedInvertedMemcpy(void *dst, void *src, int size);
void ClearRegion02093980(char *obj);

struct Ctx0209459c {
    char pad0[0x3cb];
    signed char count;
    char pad1[0x3cd - 0x3cc];
    unsigned char flags;
};

// USA: func_020945ac  (semantic: SlideAndClearEntries_020945ac)
extern "C" ARM void func_020945ac(Ctx0209459c *ctx) {
    if (ctx->count <= 0) {
        return;
    }
    int last = ctx->count - 1;
    for (int i = 0; i < last; i++) {
        VectorizedInvertedMemcpy((char*)ctx + (i + 1) * 0x34, (char*)ctx + i * 0x34, 0x34);
    }
    for (int i = last; i < 8; i++) {
        ClearRegion02093980((char*)ctx + i * 0x34);
    }
    if (ctx->count > 0) {
        ctx->count = ctx->count - 1;
    }
    if (ctx->count > 0) {
        ctx->flags = (ctx->flags | 1) & ~4;
    } else {
        ctx->flags = ctx->flags & ~4;
    }
}
