#include <globaldefs.h>

extern "C" void* Alloc(void);
extern "C" void UseIt(void*, void*);
struct Ctx { char pad[0x160]; void* field160; unsigned char field164; };
extern Ctx* g_ctx;

// USA: func_ov001_test
ARM int TestFn(void) {
    void* buf = Alloc();
    if (!buf) return 0;
    g_ctx->field160 = buf;
    g_ctx->field164 = 0;
    return 1;
}
