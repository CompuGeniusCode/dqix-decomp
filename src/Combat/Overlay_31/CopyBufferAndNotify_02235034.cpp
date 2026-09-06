#include <globaldefs.h>

extern "C" int func_020ca3b8(int, int, int);
extern "C" void func_ov031_0223e2c0(int, int);
extern int data_ov031_02290ce8;

// USA: func_ov031_02235034
ARM void CopyBufferAndNotify_02235034(int a) {
    func_020ca3b8(*(int*)((char*)&data_ov031_02290ce8 + 0x4), *(int*)((char*)&data_ov031_02290ce8 + 0x8), 0x20);
    func_ov031_0223e2c0(1, a);
}
