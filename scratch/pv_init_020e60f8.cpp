#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void _Z24ClearFourRegions02079fc8Pc(void*);
extern "C" void _Z24ClearFourRegions0207a014Pc(void*);
extern "C" int func_0200efd0(void*, void*, void*);
extern int data_02108e10;
extern int data_02108e04;

// USA: func_020e60f8
extern "C" __declspec(initcode) ARM void func_020e60f8(void) {
    _Z24ClearFourRegions02079fc8Pc(&data_02108e10);
    func_0200efd0(&data_02108e10, (void*)_Z24ClearFourRegions0207a014Pc, &data_02108e04);
}
