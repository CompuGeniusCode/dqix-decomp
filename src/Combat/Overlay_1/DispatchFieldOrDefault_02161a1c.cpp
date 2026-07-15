#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_02161a1c
ARM int DispatchFieldOrDefault_02161a1c(void* ctx) {
    char* p = (char*)func_ov017_0218b5b0() + 0x3000;
    char* q = *(char**)(p + 0x734);
    int v = *(int*)(q + 0x160);
    if (v == 0) {
        func_ov017_021d6134(ctx, 1);
    } else {
        func_ov017_021d6134(ctx, *(unsigned char*)(q + 0x164));
    }
    return 1;
}
