#include <globaldefs.h>

extern "C" void PreCall1(int);
extern "C" int PreCall2(void);
extern "C" void* Alloc(int);
extern "C" void Call1(void);
extern "C" void Call2(void*, void*);
struct Ctx { char pad[0x734]; void* field734; char pad2[0x160-4]; void* field160; unsigned char field164; };
extern void* g_other;

// USA: func_ov001_test
ARM int TestFn(void) {
    PreCall1(5);
    char* p = (char*)PreCall2() + 0x3000;
    Ctx* ctx = *(Ctx**)(p + 0x734);
    void* buf = Alloc(0x84);
    if (!buf) return 0;
    ctx->field160 = buf;
    ctx->field164 = 0;
    Call1();
    Call2(buf, g_other);
    return 1;
}
