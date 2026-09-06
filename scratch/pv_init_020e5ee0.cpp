#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void _Z23EmptyDestructor0205ec2cPv(void*);
extern "C" void _Z23EmptyDestructor0205ec30Pv(void*);
extern "C" int func_0200efd0(void*, void*, void*);
extern int data_02108760;
extern int data_02108754;

// USA: func_020e5ee0
extern "C" __declspec(initcode) ARM void func_020e5ee0(void) {
    _Z23EmptyDestructor0205ec2cPv(&data_02108760);
    func_0200efd0(&data_02108760, (void*)_Z23EmptyDestructor0205ec30Pv, &data_02108754);
}
