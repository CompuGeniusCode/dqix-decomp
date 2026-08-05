#include <globaldefs.h>

extern int data_ov027_021e33e0;
extern "C" unsigned int _Z20DisableIRQInterruptsv();
extern "C" unsigned int _Z20SetIRQInterruptStatei(unsigned int);
extern "C" unsigned int func_020c9be0(unsigned int, unsigned int);
extern "C" unsigned int func_ov027_021dcc8c();

// USA: func_ov027_021dcd20  (semantic: Trans_021dcd20)
extern "C" ARM unsigned int func_ov027_021dcd20(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    r0 = (unsigned int)_Z20DisableIRQInterruptsv();
    r1 = (unsigned int)&data_ov027_021e33e0;
    r4 = r0;
    r0 = *(unsigned int*)((char*)r1 + 0xc);
    r0 = r0 + 0x1000;
    r0 = *(unsigned int*)((char*)r0 + 0x320);
    cc = (int)(r0) - (int)(0x0);
    if (cc != 0) { goto L28; }
    r0 = (unsigned int)func_020c9be0(r0, r1);
L28:;
    r0 = (unsigned int)func_ov027_021dcc8c();
    r0 = r4;
    r0 = (unsigned int)_Z20SetIRQInterruptStatei(r0);
    return r0;
}
