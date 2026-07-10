#include <globaldefs.h>

void CopyVec3(int* dst, int* src);

// USA: func_0202ef04
ARM void CopyVec3ToField0x4(int* obj, int* src) {
    CopyVec3((int*)((char*)obj + 0x4), src);
}
