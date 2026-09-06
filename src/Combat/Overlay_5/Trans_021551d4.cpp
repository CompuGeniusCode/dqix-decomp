#include <globaldefs.h>

extern "C" unsigned int func_ov005_02155544();

// USA: func_ov005_021551d4  (semantic: Trans_021551d4)
extern "C" ARM unsigned int func_ov005_021551d4(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)func_ov005_02155544();
    r0 = r4 + 0x3000;
    r2 = *(unsigned int*)((char*)r0 + 0xdcc);
    r1 = 0x0;
    r2 = r2 | 0x20;
    *(unsigned int*)((char*)r0 + 0xdcc) = (unsigned int)r2;
    *(unsigned char*)((char*)r0 + 0xda9) = (unsigned char)r1;
    return r0;
}
