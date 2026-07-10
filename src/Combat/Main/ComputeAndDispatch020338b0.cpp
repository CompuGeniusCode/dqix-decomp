#include <globaldefs.h>

extern "C" int func_02032424(int a, void* vec);
extern "C" void func_02033834(void* obj, int value);

// USA: func_020338b0
ARM void ComputeAndDispatch020338b0(unsigned char* obj, int a) {
    int value = func_02032424(a, obj + 0x44);
    func_02033834(obj, value);
}
