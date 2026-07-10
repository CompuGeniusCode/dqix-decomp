#include <globaldefs.h>

int GetData02104304Field4();
extern "C" void func_020301c8(int a, int handle);

// USA: func_02022b90
ARM void ReleaseHandle02022b90(void* owner, int* handle) {
    func_020301c8(GetData02104304Field4(), *handle);
    *handle = -1;
}
