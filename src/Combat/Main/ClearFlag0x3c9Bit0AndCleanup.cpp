#include <globaldefs.h>

extern "C" void func_020939ac(void* obj);

// USA: func_020939fc
ARM void ClearFlag0x3c9Bit0AndCleanup(unsigned char* obj) {
    obj[0x3c9] &= ~1;
    func_020939ac(obj);
}
