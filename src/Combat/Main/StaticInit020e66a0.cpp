#include <globaldefs.h>
#pragma define_section initcode ".init" RX

extern "C" void _Z21BlankFunction02012298v(void);
extern "C" void _Z21BlankFunction0201238cv(void);
extern "C" void _Z21BlankFunction02012530v(void);
extern "C" void _Z17EmptyStub02012534v(void);
extern "C" void _Z22ClearField0x0_02046724Pi(int* field);
extern "C" int __register_global_object(void*, void*, void*);

extern int data_02114e30;
extern int data_02114e14;
extern int data_02114e54;
extern int data_02114e08;
extern int data_02114e04;

// USA: func_020e66a0
extern "C" __declspec(initcode) ARM void __sinit_020e66a0(void) {
    ((void(*)(void*))_Z21BlankFunction02012298v)(&data_02114e30);
    __register_global_object(&data_02114e30, (void*)_Z21BlankFunction0201238cv, &data_02114e14);
    ((void(*)(void*))_Z21BlankFunction02012530v)(&data_02114e54);
    __register_global_object(&data_02114e54, (void*)_Z17EmptyStub02012534v, &data_02114e08);
    _Z22ClearField0x0_02046724Pi(&data_02114e04);
}
