#include <globaldefs.h>

void CopyVec3(int* dst, int* src);

// USA: func_0202e938
ARM void CopyVec3ToField0x10(void* obj, int* src) {
    CopyVec3((int*)((char*)obj + 0x10), src);
}
