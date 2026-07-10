#include <globaldefs.h>

extern "C" void func_02042b98(void*, int, int, int, int);

// USA: func_02042b3c
ARM void InitFields02042b3c(void* obj) {
    *(int*)((char*)obj + 0x1860) = 0xc;
    *(int*)((char*)obj + 0x1864) = 0x10;
    func_02042b98(obj, 2, 0x92, 0xfc, 0x4a);
    *(unsigned char*)((char*)obj + 0x19b2) = 0;
    *(unsigned char*)((char*)obj + 0x19b1) = 0;
    *(unsigned char*)((char*)obj + 0x195b) |= 2;
}
