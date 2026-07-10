#include <globaldefs.h>

extern "C" void func_02034bc4(void* obj);

// USA: func_020484d0
ARM void SetFlag0x400Reset020484d0(void* obj) {
    func_02034bc4(obj);
    *(unsigned short*)obj |= 0x400;
    *(int*)((char*)obj + 0xb0) = 0;
    *(int*)((char*)obj + 0xac) = 0;
}
