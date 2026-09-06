#include <globaldefs.h>

struct U16Field0x6_020375f8;
extern "C" int _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8*);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// USA: func_02053ed8
ARM void CaptureTransformState02053ed8(void* obj) {
    *(int*)((char*)obj + 0x15c) = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)obj);
    _ZN8Vector3iaSERKS_((int*)((char*)obj + 0x160), (int*)((char*)obj + 0x44));
    _ZN8Vector3iaSERKS_((int*)((char*)obj + 0x16c), (int*)((char*)obj + 0x50));
}
