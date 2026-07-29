#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void _Z22ClearAndReturn0207c244Pc(void*);
extern "C" void _Z32ClearRegionAndReturnSelf020269d0Pc(void*);
extern "C" int func_0200efd0(void*, void*, void*);
extern int data_02108e90;
extern int data_02108e84;

// USA: func_020e6234
extern "C" __declspec(initcode) ARM void func_020e6234(void) {
    _Z22ClearAndReturn0207c244Pc(&data_02108e90);
    func_0200efd0(&data_02108e90, (void*)_Z32ClearRegionAndReturnSelf020269d0Pc, &data_02108e84);
}
