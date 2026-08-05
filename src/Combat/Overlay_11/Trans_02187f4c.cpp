#include <globaldefs.h>


// USA: func_ov011_02187f4c  (semantic: Trans_02187f4c)
extern "C" ARM unsigned int func_ov011_02187f4c(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r2 = 0x4000304;
    r1 = *(unsigned short*)((char*)r2 + 0x0);
    r1 = r1 & ~0x8000;
    r0 = r1 | (r0 << 15);
    *(unsigned short*)((char*)r2 + 0x0) = (unsigned short)r0;
    return r0;
}
