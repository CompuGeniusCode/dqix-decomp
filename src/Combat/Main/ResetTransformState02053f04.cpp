#include <globaldefs.h>

extern "C" void __clear(void* buf, int n);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern int data_020f0420[];

// USA: func_02053f04
ARM void ResetTransformState02053f04(void* obj) {
    int buf[3];
    __clear(buf, 0xc);
    *(int*)((char*)obj + 0x15c) = data_020f0420[1];
    _ZN8Vector3iaSERKS_((int*)((char*)obj + 0x160), buf);
    _ZN8Vector3iaSERKS_((int*)((char*)obj + 0x16c), buf);
}
