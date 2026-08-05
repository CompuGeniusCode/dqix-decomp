#include <globaldefs.h>

extern int data_ov014_021896bc;
extern "C" unsigned int _Z21GetData02104304Field4v(unsigned int);
extern "C" unsigned int _Z23CallFunc0202fa38ZeroPadiii(unsigned int, unsigned int, unsigned int);

// USA: func_ov014_02185c48  (semantic: Trans_02185c48)
extern "C" ARM unsigned int func_ov014_02185c48(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    r4 = r0;
    r0 = *(unsigned char*)((char*)r4 + 0x81);
    cc = (int)(r0 & 0x10);
    if (cc == 0) { return r0; }
    r0 = (unsigned int)_Z21GetData02104304Field4v(r0);
    r1 = *(unsigned char*)((char*)r4 + 0x7e);
    cc = (int)(r1) - (int)(0x0);
    if (cc != 0) { return r0; }
    r1 = (unsigned int)&data_ov014_021896bc;
    r2 = 0x0;
    r0 = (unsigned int)_Z23CallFunc0202fa38ZeroPadiii(r0, r1, r2);
    *(unsigned int*)((char*)r4 + 0x70) = (unsigned int)r0;
    r0 = *(unsigned char*)((char*)r4 + 0x7e);
    r0 = r0 + 0x1;
    *(unsigned char*)((char*)r4 + 0x7e) = (unsigned char)r0;
    return r0;
}
