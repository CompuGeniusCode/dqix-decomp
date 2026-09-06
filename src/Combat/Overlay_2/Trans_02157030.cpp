#include <globaldefs.h>

extern "C" unsigned int _Z23FindElementByC40205d81cP15Struct_0205d81ci(unsigned int);

// USA: func_ov002_02157030  (semantic: Trans_02157030)
extern "C" ARM unsigned int func_ov002_02157030(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3, unsigned int a8, unsigned int a9) {
    int cc = 0;
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    r0 = r0 + 0x2c8;
    r0 = r0 + 0xc00;
    r5 = r2;
    r4 = r3;
    r0 = (unsigned int)_Z23FindElementByC40205d81cP15Struct_0205d81ci(r0);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { return r0; }
    r3 = *(short*)((char*)r0 + 0xac);
    r2 = a8;
    r1 = a9;
    *(unsigned short*)((char*)r5 + 0x0) = (unsigned short)r3;
    r3 = *(short*)((char*)r0 + 0xae);
    *(unsigned short*)((char*)r4 + 0x0) = (unsigned short)r3;
    r3 = *(short*)((char*)r0 + 0xa8);
    *(unsigned short*)((char*)r2 + 0x0) = (unsigned short)r3;
    r0 = *(short*)((char*)r0 + 0xaa);
    *(unsigned short*)((char*)r1 + 0x0) = (unsigned short)r0;
    return r0;
}
