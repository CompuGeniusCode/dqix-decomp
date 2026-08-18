#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void _Z23EmptyDestructor0205ec2cPv(void* obj);
extern "C" void _Z23EmptyDestructor0205ec30Pv(void* obj);
extern "C" void func_0200efd0(int c, int b, void* node);

extern void* data_02108760;
extern void* data_02108754;

// USA: func_020e5ee0
extern "C" __declspec(initcode) ARM void func_020e5ee0(void) {
    _Z23EmptyDestructor0205ec2cPv(&data_02108760);
    func_0200efd0((int)&data_02108760, (int)_Z23EmptyDestructor0205ec30Pv, &data_02108754);
}
