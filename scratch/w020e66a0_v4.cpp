#include <globaldefs.h>
#pragma define_section initcode ".init" RX

void BlankFunction02012298(void);
void BlankFunction0201238c(void);
void BlankFunction02012530(void);
void EmptyStub02012534(void);
void ClearField0x0_02046724(int* field);

struct Node0200efd0 {
    struct Node0200efd0* next;
    int b;
    int c;
};

extern "C" void func_0200efd0(int c, int b, struct Node0200efd0* node);

extern int data_02114e30;
extern struct Node0200efd0 data_02114e14;
extern int data_02114e54;
extern struct Node0200efd0 data_02114e08;
extern int data_02114e04;

static inline void RegisterReset020e66a0(void (*blank)(void), int addr, void (*fn)(void), struct Node0200efd0* node) {
    blank();
    func_0200efd0(addr, (int)fn, node);
}

// USA: func_020e66a0
extern "C" __declspec(initcode) ARM void func_020e66a0(void) {
    RegisterReset020e66a0(BlankFunction02012298, (int)&data_02114e30, BlankFunction0201238c, &data_02114e14);
    RegisterReset020e66a0(BlankFunction02012530, (int)&data_02114e54, EmptyStub02012534, &data_02114e08);
    ClearField0x0_02046724(&data_02114e04);
}
