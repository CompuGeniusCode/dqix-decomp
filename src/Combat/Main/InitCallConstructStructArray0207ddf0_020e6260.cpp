#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct _Z18InitStruct0207d7c0P12Init0207d7c0;
extern "C" ARM void* _Z28ConstructStructArray0207ddf0P12Init0207d7c0(struct _Z18InitStruct0207d7c0P12Init0207d7c0* obj);
extern "C" ARM void* _Z28ConstructStructArray0207de1cP12Init0207d7c0(struct _Z18InitStruct0207d7c0P12Init0207d7c0* obj);

extern "C" void func_0200efd0(int c, int b, void* node);

extern _Z18InitStruct0207d7c0P12Init0207d7c0 data_02108ea8;
extern int data_02108e9c;

// USA: func_020e6260
extern "C" __declspec(initcode) ARM void func_020e6260(void) {
    _Z28ConstructStructArray0207ddf0P12Init0207d7c0(&data_02108ea8);
    func_0200efd0((int)&data_02108ea8, (int)_Z28ConstructStructArray0207de1cP12Init0207d7c0, &data_02108e9c);
}
