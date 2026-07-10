#include <globaldefs.h>

extern "C" void func_0200f374(void* buf, int n);
extern "C" void func_02013158(void* a, void* b, void* c, void* d);

struct UnitScaleVec0201310c { unsigned int v[3]; };
extern UnitScaleVec0201310c data_020e6dfc;

// USA: func_0201310c
ARM void InitWithUnitScaleVec0201310c(void* obj) {
    char buf[12];
    int flag;
    UnitScaleVec0201310c scale;
    func_0200f374(buf, 0xc);
    scale = data_020e6dfc;
    flag = 0;
    func_02013158(obj, buf, &flag, &scale);
}
