#include <globaldefs.h>

extern "C" unsigned int func_02012fe4();
extern "C" unsigned int func_ov017_021d6134(unsigned int, unsigned int);

// USA: func_ov023_021ea9b0  (semantic: Trans_021ea9b0)
extern "C" ARM unsigned int func_ov023_021ea9b0(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)func_02012fe4();
    r1 = *(unsigned int*)((char*)r0 + 0x8);
    r0 = r4;
    r1 = *(unsigned char*)((char*)r1 + 0xc);
    r1 = r1 << 0x1b;
    r1 = r1 >> 0x1f;
    r0 = (unsigned int)func_ov017_021d6134(r0, r1);
    r0 = 0x1;
    return r0;
}
