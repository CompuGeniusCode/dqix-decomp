#include <globaldefs.h>

extern int data_ov003_0217f3b2;
extern int data_ov003_0217f3b4;

// USA: func_ov003_0215ec68  (semantic: Trans_0215ec68)
extern "C" ARM unsigned int func_ov003_0215ec68(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r12 = 0;
    r3 = (unsigned int)&data_ov003_0217f3b2;
    r12 = r0 << 0x2;
    r0 = (unsigned int)&data_ov003_0217f3b4;
    r3 = *(short*)((char*)r3 + (r12));
    r0 = *(short*)((char*)r0 + (r12));
    *(unsigned short*)((char*)r1 + 0x0) = (unsigned short)r3;
    *(unsigned short*)((char*)r2 + 0x0) = (unsigned short)r0;
    return r0;
}
