#include <globaldefs.h>

extern "C" void* Alloc(void);
extern "C" void Call1(void);
extern "C" void Call2(void*, void*);
extern void* g_other;

// USA: func_ov001_test
ARM int TestFn(char* ctx) {
    void* buf = Alloc();
    if (buf) {
        *(void**)(ctx + 0x160) = buf;
        *(unsigned char*)(ctx + 0x164) = 0;
        Call1();
        Call2(buf, g_other);
        return 1;
    }
    return 0;
}
