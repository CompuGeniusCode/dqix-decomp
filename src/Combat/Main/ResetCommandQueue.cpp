#include <globaldefs.h>

void WaitUntilField4Zero(void);
extern "C" void func_020ca430(void* dst, int pattern, int size);
extern volatile int data_0210cf78[];

// USA: func_020b6998
ARM void ResetCommandQueue(void) {
    int* p;
    if (data_0210cf78[1] != 0) {
        WaitUntilField4Zero();
    }
    p = (int*)data_0210cf78[0];
    if (p != 0 && p[0] != 0) {
        func_020ca430((char*)p + 4, 0x4000400, p[0] << 2);
        ((int*)data_0210cf78[0])[0] = 0;
    }
}
