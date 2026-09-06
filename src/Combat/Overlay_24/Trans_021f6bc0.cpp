#include <globaldefs.h>

extern "C" unsigned int _fmul(unsigned int, unsigned int);

// USA: func_ov024_021f6bc0  (semantic: Trans_021f6bc0)
extern "C" ARM unsigned int func_ov024_021f6bc0(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r1 = *(unsigned int*)((char*)r4 + 0x14);
    r0 = 0x3f400000;
    r0 = (unsigned int)_fmul(r0, r1);
    *(unsigned int*)((char*)r4 + 0x1c) = (unsigned int)r0;
    r1 = *(unsigned int*)((char*)r4 + 0x18);
    r0 = 0x3f400000;
    r0 = (unsigned int)_fmul(r0, r1);
    *(unsigned int*)((char*)r4 + 0x20) = (unsigned int)r0;
    r0 = 0x1;
    return r0;
}
