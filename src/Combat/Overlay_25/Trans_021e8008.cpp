#include <globaldefs.h>

extern int data_02109bf4;
extern "C" unsigned int _Z36ResetAndDispatchActorContext0209c6d8Pvs(unsigned int, unsigned int);

// USA: func_ov025_021e8008  (semantic: Trans_021e8008)
extern "C" ARM unsigned int func_ov025_021e8008(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r1 = *(unsigned int*)((char*)r0 + 0x8);
    r0 = (unsigned int)&data_02109bf4;
    r0 = (unsigned int)_Z36ResetAndDispatchActorContext0209c6d8Pvs(r0, r1);
    r0 = 0x1;
    return r0;
}
