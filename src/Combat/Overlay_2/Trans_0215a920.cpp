#include <globaldefs.h>


// USA: func_ov002_0215a920  (semantic: Trans_0215a920)
extern "C" ARM unsigned int func_ov002_0215a920(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r1 = 0x0;
    *(unsigned char*)((char*)r0 + 0x0) = (unsigned char)r1;
    *(unsigned int*)((char*)r0 + 0x4) = (unsigned int)r1;
    r1 = r1 - 0x1;
    *(unsigned int*)((char*)r0 + 0x8) = (unsigned int)r1;
    return r0;
}
