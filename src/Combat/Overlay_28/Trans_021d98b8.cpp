#include <globaldefs.h>


// USA: func_ov028_021d98b8  (semantic: Trans_021d98b8)
extern "C" ARM unsigned int func_ov028_021d98b8(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r1 = 0x0;
    *(unsigned int*)((char*)r0 + 0x4) = (unsigned int)r1;
    *(unsigned short*)((char*)r0 + 0x8) = (unsigned short)r1;
    *(unsigned short*)((char*)r0 + 0xa) = (unsigned short)r1;
    r1 = 0x3f800000;
    *(unsigned int*)((char*)r0 + 0x0) = (unsigned int)r1;
    return r0;
}
