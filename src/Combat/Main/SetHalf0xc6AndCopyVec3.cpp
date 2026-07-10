#include <globaldefs.h>

void CopyVec3(int* dst, int* src);

// USA: func_02033e18
ARM void SetHalf0xc6AndCopyVec3(void* obj, int* src, short val) {
    *(short*)((char*)obj + 0xc6) = val;
    CopyVec3((int*)((char*)obj + 0xc8), src);
}
