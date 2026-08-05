#include <globaldefs.h>

extern int data_02108760;
extern int data_02109bf4;
extern "C" unsigned int _Z18GetByteFieldAt0xccPh(unsigned int, unsigned int);
extern "C" unsigned int _Z20GetField0xcc0209ca98Pc(unsigned int);

// USA: func_ov002_0215b234  (semantic: Trans_0215b234)
extern "C" ARM unsigned int func_ov002_0215b234(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)&data_02109bf4;
    r0 = (unsigned int)_Z20GetField0xcc0209ca98Pc(r0);
    r1 = r4 + 0x1000;
    *(unsigned char*)((char*)r1 + 0xc2c) = (unsigned char)r0;
    r0 = (unsigned int)&data_02108760;
    r0 = (unsigned int)_Z18GetByteFieldAt0xccPh(r0, r1);
    r1 = r4 + 0x1000;
    *(unsigned char*)((char*)r1 + 0xc2d) = (unsigned char)r0;
    return r0;
}
