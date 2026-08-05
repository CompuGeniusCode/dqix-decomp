#include <globaldefs.h>


// USA: func_ov025_021eb044  (semantic: Trans_021eb044)
extern "C" ARM unsigned int func_ov025_021eb044(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r0 = r0 + 0x500;
    *(unsigned short*)((char*)r0 + 0x7c) = (unsigned short)r1;
    return r0;
}
