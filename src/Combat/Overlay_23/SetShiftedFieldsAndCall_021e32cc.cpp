#include <globaldefs.h>

extern "C" int func_0205ac40(void*, void*);

// USA: func_ov023_021e32cc
ARM int SetShiftedFieldsAndCall_021e32cc(void* obj, int a, int b) {
    char* ctx = *(char**)((char*)obj + 0xcc);
    *(int*)(ctx + 0x154) = a << 12;
    *(int*)(ctx + 0x158) = b << 12;
    *(unsigned char*)(ctx + 0x162) = 0x72;
    *(unsigned char*)(ctx + 0x166) = 2;
    return func_0205ac40(*(void**)((char*)obj + 0xc8), ctx + 0x140);
}
