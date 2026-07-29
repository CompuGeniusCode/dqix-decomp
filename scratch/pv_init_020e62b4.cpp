#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void _Z25InitAndReturnSelf0208f4bcP14Struct0208e9f4(void*);
extern "C" void _Z25InitAndReturnSelf0208f4d0Pv(void*);
extern "C" int func_0200efd0(void*, void*, void*);
extern int data_02109020;
extern int data_02109014;

// USA: func_020e62b4
extern "C" __declspec(initcode) ARM void func_020e62b4(void) {
    _Z25InitAndReturnSelf0208f4bcP14Struct0208e9f4(&data_02109020);
    func_0200efd0(&data_02109020, (void*)_Z25InitAndReturnSelf0208f4d0Pv, &data_02109014);
}
