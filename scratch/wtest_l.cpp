#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* Alloc(void);
extern "C" void Call1(void);
extern "C" void Call2(void*, void*);
extern void* g_other;

// USA: func_ov001_test
ARM int TestFn(char* ctx) {
    void* buf = Alloc();
    if (!buf) return 0;
    *(void**)(ctx + 0x160) = buf;
    memset(ctx + 0x164, 0, 1);
    Call1();
    Call2(buf, g_other);
    return 1;
}
