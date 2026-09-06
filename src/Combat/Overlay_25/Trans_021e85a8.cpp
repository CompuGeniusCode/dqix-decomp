#include <globaldefs.h>

extern int data_ov025_021ef988;

// USA: func_ov025_021e85a8  (semantic: Trans_021e85a8)
extern "C" ARM unsigned int func_ov025_021e85a8(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r1 = (unsigned int)&data_ov025_021ef988;
    r2 = *(unsigned short*)((char*)r0 + 0x8);
    r1 = *(unsigned int*)((char*)r1 + 0xc);
    r0 = 0x1;
    r1 = r1 + 0x700;
    *(unsigned short*)((char*)r1 + 0x4a) = (unsigned short)r2;
    return r0;
}
