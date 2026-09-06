#include <globaldefs.h>


// USA: func_ov023_021e4e3c  (semantic: Trans_021e4e3c)
extern "C" ARM unsigned int func_ov023_021e4e3c(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    r1 = r0 + 0x600;
    r1 = *(unsigned short*)((char*)r1 + 0x34);
    cc = (int)(r1 & 0x1000);
    if (cc == 0) { return r0; }
    cc = (int)(r1 & 0x2000);
    if (cc != 0) { return r0; }
    r1 = *(unsigned char*)((char*)r0 + 0x636);
    cc = (int)(r1) - (int)(0x0);
    if (cc != 0) { return r0; }
    r1 = r0 + 0x400;
    r3 = *(signed char*)((char*)r1 + 0xe6);
    r2 = 0x1;
    r1 = 0x0;
    *(unsigned char*)((char*)r0 + 0x4e7) = (unsigned char)r3;
    *(unsigned char*)((char*)r0 + 0x4e6) = (unsigned char)r2;
    *(unsigned char*)((char*)r0 + 0x4e4) = (unsigned char)r1;
    r1 = *(unsigned char*)((char*)r0 + 0x636);
    r1 = r1 + 0x1;
    *(unsigned char*)((char*)r0 + 0x636) = (unsigned char)r1;
    return r0;
}
