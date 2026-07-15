#include <globaldefs.h>

void CopyVec3(int* dst, int* src);

// USA: func_ov000_0216f1e4
ARM void SetPosAndFields0216f1e4(void* obj, int* srcVec3, int a, int b) {
    CopyVec3((int*)((char*)obj + 0x264), srcVec3);
    *(int*)((char*)obj + 0x270) = a;
    *(int*)((char*)obj + 0x274) = b;
}
