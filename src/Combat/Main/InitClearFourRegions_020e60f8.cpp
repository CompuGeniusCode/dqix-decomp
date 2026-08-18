#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void _Z24ClearFourRegions02079fc8Pc(void* obj);
extern "C" void _Z24ClearFourRegions0207a014Pc(void* obj);
extern "C" void func_0200efd0(int c, int b, void* node);

extern void* data_02108e10;
extern void* data_02108e04;

// USA: func_020e60f8
extern "C" __declspec(initcode) ARM void func_020e60f8(void) {
    _Z24ClearFourRegions02079fc8Pc(&data_02108e10);
    func_0200efd0((int)&data_02108e10, (int)_Z24ClearFourRegions0207a014Pc, &data_02108e04);
}
