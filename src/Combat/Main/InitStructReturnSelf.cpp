#include <globaldefs.h>

extern "C" void func_0207e264(void* obj);

// USA: func_0207e23c
ARM void* InitStructReturnSelf(void* obj) {
    func_0207e264(obj);
    return obj;
}
