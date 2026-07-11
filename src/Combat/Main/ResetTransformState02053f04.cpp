#include <globaldefs.h>

extern "C" void func_0200f374(void* buf, int n);
void CopyVec3(int* dst, int* src);
extern int data_020f0420[];

// USA: func_02053f04
ARM void ResetTransformState02053f04(void* obj) {
    int buf[3];
    func_0200f374(buf, 0xc);
    *(int*)((char*)obj + 0x15c) = data_020f0420[1];
    CopyVec3((int*)((char*)obj + 0x160), buf);
    CopyVec3((int*)((char*)obj + 0x16c), buf);
}
