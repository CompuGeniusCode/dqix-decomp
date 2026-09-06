#include <globaldefs.h>


// USA: func_ov025_021ed344  (semantic: Trans_021ed344)
extern "C" ARM unsigned int func_ov025_021ed344(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r0 = r0 + 0x100;
    *(unsigned short*)((char*)r0 + 0x60) = (unsigned short)r1;
    return r0;
}
