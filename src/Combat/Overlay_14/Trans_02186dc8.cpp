#include <globaldefs.h>

extern "C" unsigned int _Z28CallFunc0204b088OverList0x2cP12Cont0207fd88(unsigned int);
extern "C" unsigned int func_ov014_02185c90(unsigned int);

// USA: func_ov014_02186dc8  (semantic: Trans_02186dc8)
extern "C" ARM unsigned int func_ov014_02186dc8(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    r4 = r0;
    r0 = *(unsigned char*)((char*)r4 + 0x17a);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { goto L1c; }
    r0 = *(unsigned int*)((char*)r4 + 0xc0);
    r0 = (unsigned int)_Z28CallFunc0204b088OverList0x2cP12Cont0207fd88(r0);
L1c:;
    r0 = r4;
    r0 = (unsigned int)func_ov014_02185c90(r0);
    return r0;
}
