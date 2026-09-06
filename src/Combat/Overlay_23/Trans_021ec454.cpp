#include <globaldefs.h>


// USA: func_ov023_021ec454  (semantic: Trans_021ec454)
extern "C" ARM unsigned int func_ov023_021ec454(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r12 = 0;
    unsigned int r14 = 0;
    r14 = 0x400000c;
    r12 = *(unsigned short*)((char*)r14 + 0x0);
    r12 = r12 & 0x43;
    r0 = r12 | (r0 << 14);
    r0 = r0 | (r1 << 7);
    r0 = r0 | (r2 << 8);
    r0 = r0 | (r3 << 2);
    *(unsigned short*)((char*)r14 + 0x0) = (unsigned short)r0;
    return r0;
}
