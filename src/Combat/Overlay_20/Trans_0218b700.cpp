#include <globaldefs.h>

extern "C" unsigned int _Z20InitControllerObjectPc();
extern "C" unsigned int _Z26GetGlobalField0x1c020421a0v();

// USA: func_ov020_0218b700  (semantic: Trans_0218b700)
extern "C" ARM unsigned int func_ov020_0218b700(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r0 = (unsigned int)_Z26GetGlobalField0x1c020421a0v();
    r0 = (unsigned int)_Z20InitControllerObjectPc();
    return r0;
}
