#include <globaldefs.h>
#pragma optimize_for_size off

struct Entry0200dad4 {
    unsigned int key;
    unsigned int sizeFlag;
    int pad8;
};

struct SearchCtx0200dad4 {
    unsigned int f0;
    void* f4;
    void* f8;
    Entry0200dad4* rangeStart;
    Entry0200dad4* rangeEnd;
};

extern "C" int func_0200f29c(SearchCtx0200dad4* ctx, unsigned int key);
extern "C" ARM void* func_0200da70(Entry0200dad4* arr, int count, unsigned int target);
extern "C" ARM void* func_0200f2bc(void* ptr);
extern "C" void* func_0200d9e4(void* ptr, int* outVal);

// USA: func_0200dad4
extern "C" ARM void* func_0200dad4(unsigned int key, SearchCtx0200dad4* ctx) {
    ctx->f4 = 0;
    ctx->f8 = 0;
    void* ok = (void*)(int)func_0200f29c(ctx, key);
    if (!ok) {
        return ok;
    }

    int count = ((int)ctx->rangeEnd - (int)ctx->rangeStart) / 12;
    Entry0200dad4* e = (Entry0200dad4*)func_0200da70(ctx->rangeStart, count, key);
    if (!e) {
        return e;
    }

    ctx->f4 = (e->sizeFlag & 1) ? (char*)e + 8 : (void*)e->pad8;
    ctx->f0 = e->key;
    int remaining = key - e->key;
    void* p = func_0200f2bc(ctx->f4);

    int acc = 0;
    int local2, local1, local0;
    for (;;) {
        p = func_0200d9e4(p, &local2);
        if (local2 == 0) return p;
        p = func_0200d9e4(p, &local1);
        p = func_0200d9e4(p, &local0);
        int t = acc + local2;
        if ((unsigned)remaining < (unsigned)t) return p;
        acc = t + local1;
        if ((unsigned)remaining <= (unsigned)acc) break;
    }

    ctx->f8 = (char*)ctx->f4 + local0;
    return ctx->f8;
}
