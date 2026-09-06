#include <globaldefs.h>

extern int data_ov027_021e33e0;

// USA: func_ov027_021dcee8  (semantic: Trans_021dcee8)
extern "C" ARM unsigned int func_ov027_021dcee8(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r1 = (unsigned int)&data_ov027_021e33e0;
    *(unsigned short*)((char*)r1 + 0x26) = (unsigned short)r0;
    return r0;
}
