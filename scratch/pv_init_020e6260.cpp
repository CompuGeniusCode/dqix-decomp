#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void _Z28ConstructStructArray0207ddf0P12Init0207d7c0(void*);
extern "C" void _Z28ConstructStructArray0207de1cP12Init0207d7c0(void*);
extern "C" int func_0200efd0(void*, void*, void*);
extern int data_02108ea8;
extern int data_02108e9c;

// USA: func_020e6260
extern "C" __declspec(initcode) ARM void func_020e6260(void) {
    _Z28ConstructStructArray0207ddf0P12Init0207d7c0(&data_02108ea8);
    func_0200efd0(&data_02108ea8, (void*)_Z28ConstructStructArray0207de1cP12Init0207d7c0, &data_02108e9c);
}
