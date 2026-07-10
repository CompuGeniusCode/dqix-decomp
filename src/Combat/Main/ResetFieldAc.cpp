#include <globaldefs.h>

extern "C" void func_02034bc4(void*);

// USA: func_02072ac4
ARM void ResetFieldAc(void* obj) {
    func_02034bc4(obj);
    *(int*)((char*)obj + 0xac) = -1;
}
