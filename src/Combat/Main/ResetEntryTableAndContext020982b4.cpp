#include <globaldefs.h>

extern "C" void func_02098364(void* entry);

struct Entry020982b4 {
    unsigned char pad[0xe8];
};

struct Ctx020982b4 {
    unsigned char pad0[0xb34];
    int b34;
    int b38;
    int b3c;
    unsigned char b40;
    unsigned char b41;
    unsigned char b42;
    unsigned char pad_b43;
    int b44;
    int b48;
    int b4c;
    int b50;
    int b54;
    int b58;
    int b5c;
    unsigned char b60;
    unsigned char b61;
    unsigned char b62;
};

// USA: func_020982b4  (semantic: ResetEntryTableAndContext020982b4)
extern "C" ARM void func_020982b4(Entry020982b4* arr) {
    Ctx020982b4* ctx = (Ctx020982b4*)((char*)arr + 0x1000);
    int zero = 0;
    ctx->b34 = zero;
    ctx->b38 = zero;
    ctx->b3c = 1;
    ctx->b40 = 1;
    ctx->b41 = 1;
    ctx->b42 = zero;
    ctx->b44 = zero;
    ctx->b48 = zero;
    ctx->b4c = zero;
    ctx->b50 = zero;
    ctx->b54 = zero;
    ctx->b60 = 1;
    ctx->b61 = zero;
    ctx->b62 = zero;
    *(unsigned short*)((char*)arr + 0x1b64) = zero;
    ctx->b58 = zero;
    Entry020982b4* p = arr;
    ctx->b5c = zero;
    for (int i = 0; i < 30; i++, p++) {
        func_02098364(p);
    }
    for (int i = 0; i < 3; i++) {
        *(int*)((char*)arr + i * 4 + 0x1b68) = -1;
    }
    *(int*)((char*)arr + 0x1b74) = 0;
}
