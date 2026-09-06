#include <globaldefs.h>


// USA: func_ov025_021ed110  (semantic: Trans_021ed110)
extern "C" ARM unsigned int func_ov025_021ed110(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r0 = r0 + 0x300;
    *(unsigned short*)((char*)r0 + 0x4) = (unsigned short)r1;
    return r0;
}
