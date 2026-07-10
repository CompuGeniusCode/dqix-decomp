#include <globaldefs.h>

void CopyVec3(int* dst, int* src);
extern "C" void func_0202e5d8(void* obj, int a, int b, int c);

// USA: func_0202ec5c
ARM void CopyVec3ToField0x10AndCall0202e5d8(char* obj, int* src) {
    CopyVec3((int*)(obj + 0x10), src);
    func_0202e5d8(obj, *(int*)(obj + 0x70), *(int*)(obj + 0x74), *(int*)(obj + 0x78));
}
