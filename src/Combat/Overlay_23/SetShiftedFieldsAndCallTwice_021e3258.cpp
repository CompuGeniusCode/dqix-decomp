#include <globaldefs.h>

extern "C" int func_0205ac40(void*, void*);

// USA: func_ov023_021e3258
ARM int SetShiftedFieldsAndCallTwice_021e3258(void* obj, int a, int b, int c, short d) {
    char* ctx = *(char**)((char*)obj + 0xcc);
    *(int*)(ctx + 0x104) = a << 12;
    *(int*)(ctx + 0x108) = b << 12;
    *(unsigned char*)(ctx + 0x112) = 0x76;
    *(unsigned char*)(ctx + 0x116) = 2;
    func_0205ac40(*(void**)((char*)obj + 0xc8), ctx + 0xf0);
    ctx = *(char**)((char*)obj + 0xcc);
    *(int*)(ctx + 0x12c) = c << 12;
    *(int*)(ctx + 0x130) = d << 12;
    *(unsigned char*)(ctx + 0x13a) = 0x75;
    *(unsigned char*)(ctx + 0x13e) = 2;
    return func_0205ac40(*(void**)((char*)obj + 0xc8), ctx + 0x118);
}
