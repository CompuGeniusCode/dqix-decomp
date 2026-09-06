#include <globaldefs.h>

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// USA: func_ov000_0216f1e4
ARM void SetPosAndFields0216f1e4(void* obj, int* srcVec3, int a, int b) {
    _ZN8Vector3iaSERKS_((int*)((char*)obj + 0x264), srcVec3);
    *(int*)((char*)obj + 0x270) = a;
    *(int*)((char*)obj + 0x274) = b;
}
