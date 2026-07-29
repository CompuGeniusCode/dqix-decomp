#include <globaldefs.h>
#pragma define_section initcode ".init" RX

void BlankFunction02012298(void);
void BlankFunction0201238c(void);
void BlankFunction02012530(void);
void EmptyStub02012534(void);
void ClearField0x0_02046724(int* field);
extern "C" int func_0200efd0(void*, void*, void*);

extern int data_02114e30;
extern int data_02114e14;
extern int data_02114e54;
extern int data_02114e08;
extern int data_02114e04;

// USA: func_020e66a0
extern "C" __declspec(initcode) ARM void func_020e66a0(void) {
    ((void(*)(void*))BlankFunction02012298)(&data_02114e30);
    func_0200efd0(&data_02114e30, (void*)BlankFunction0201238c, &data_02114e14);
    ((void(*)(void*))BlankFunction02012530)(&data_02114e54);
    func_0200efd0(&data_02114e54, (void*)EmptyStub02012534, &data_02114e08);
    ClearField0x0_02046724(&data_02114e04);
}
