#include <globaldefs.h>


// USA: func_ov002_02153e90  (semantic: Trans_02153e90)
extern "C" ARM unsigned int func_ov002_02153e90(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r1 = 0x0;
    *(unsigned char*)((char*)r0 + 0x0) = (unsigned char)r1;
    *(unsigned short*)((char*)r0 + 0x2) = (unsigned short)r1;
    *(unsigned char*)((char*)r0 + 0x4) = (unsigned char)r1;
    return r0;
}
