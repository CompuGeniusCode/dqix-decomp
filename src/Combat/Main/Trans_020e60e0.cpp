#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern int data_020f0d70;

// USA: func_020e60e0  (semantic: Trans_020e60e0)
extern "C" __declspec(initcode) ARM unsigned int func_020e60e0(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r0 = (unsigned int)&data_020f0d70;
    r1 = *(unsigned int*)((char*)r0 + 0x14);
    r1 = r1 + 0xb;
    *(unsigned int*)((char*)r0 + 0x18) = (unsigned int)r1;
    return r0;
}
