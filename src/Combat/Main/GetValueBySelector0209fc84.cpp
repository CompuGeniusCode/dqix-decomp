#include <globaldefs.h>

struct Context0209fc84 {
    char pad0[4];
    char* data;
    char pad2[0x90];
    int field98;
};

// USA: func_0209fc84
ARM int GetValueBySelector0209fc84(struct Context0209fc84* ctx, int selector) {
    return (selector == 0) ? *(unsigned char*)(ctx->data + 0x8e07) : ctx->field98;
}
