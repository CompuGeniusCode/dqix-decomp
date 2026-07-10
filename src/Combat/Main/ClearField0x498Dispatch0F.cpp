#include <globaldefs.h>

extern "C" void func_020649b0(void*, int, int);

// USA: func_02064a08
ARM void ClearField0x498Dispatch0F(void* obj, int arg) {
    *(int*)((char*)obj + 0x498) = 0;
    func_020649b0(obj, 0xf, arg);
}
