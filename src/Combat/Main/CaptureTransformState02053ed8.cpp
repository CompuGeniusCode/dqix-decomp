#include <globaldefs.h>

extern "C" int func_020375f8(void* obj);
void CopyVec3(int* dst, int* src);

// USA: func_02053ed8
ARM void CaptureTransformState02053ed8(void* obj) {
    *(int*)((char*)obj + 0x15c) = func_020375f8(obj);
    CopyVec3((int*)((char*)obj + 0x160), (int*)((char*)obj + 0x44));
    CopyVec3((int*)((char*)obj + 0x16c), (int*)((char*)obj + 0x50));
}
