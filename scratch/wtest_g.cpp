#include <globaldefs.h>

class Alloc { public: void* Allocate(unsigned int); };
extern "C" void Call1(void);
extern "C" void Call2(void*, void*);
struct Ctx { char pad[0x160]; void* field160; unsigned char field164; };
extern Alloc* g_alloc;
extern Ctx** g_ctxptr;
extern void* g_other;

// USA: func_ov001_test
ARM int TestFn(void) {
    Ctx* ctx = *g_ctxptr;
    void* buf = g_alloc->Allocate(0x84);
    if (!buf) return 0;
    ctx->field160 = buf;
    ctx->field164 = 0;
    Call1();
    Call2(buf, g_other);
    return 1;
}
