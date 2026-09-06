#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct Node0200efd0 {
    struct Node0200efd0* next;
    int b;
    int c;
};

void BlankFunction02012298(void);
void BlankFunction0201238c(void);
void BlankFunction02012530(void);
void EmptyStub02012534(void);
void ClearField0x0_02046724(int* field);
extern "C" void func_0200efd0(int c, int b, struct Node0200efd0* node);

extern int data_02114e30;
extern int data_02114e14;
extern int data_02114e54;
extern int data_02114e08;
extern int data_02114e04;

// USA: func_020e66a0
extern "C" __declspec(initcode) ARM void func_020e66a0(void) {
    int addr1 = (int)&data_02114e30;
    BlankFunction02012298();
    func_0200efd0(addr1, (int)&BlankFunction0201238c, (struct Node0200efd0*)&data_02114e14);
    int addr2 = (int)&data_02114e54;
    BlankFunction02012530();
    func_0200efd0(addr2, (int)&EmptyStub02012534, (struct Node0200efd0*)&data_02114e08);
    ClearField0x0_02046724(&data_02114e04);
}
