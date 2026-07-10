#include <globaldefs.h>

int GetData02104304Field4();
extern "C" void func_020301c8(int);
extern "C" void func_020938f0(void* obj);

// USA: func_020939ac
ARM void ReleaseHandleField340(void* obj) {
    int token = GetData02104304Field4();
    if (*(int*)((char*)obj + 0x340) >= 0) {
        func_020301c8(token);
        *(int*)((char*)obj + 0x340) = -1;
    }
    func_020938f0(obj);
}
