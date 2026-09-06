#include <globaldefs.h>

extern "C" unsigned int _Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(unsigned int);
extern "C" unsigned int _Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(unsigned int);
extern "C" unsigned int _Z35CallFunc0204c8f0OverEntries0207fd00P11Obj0207fd00(unsigned int);
extern "C" unsigned int func_0207fe80(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" unsigned int func_ov014_02186e2c(unsigned int);

// USA: func_ov014_02186d7c  (semantic: Trans_02186d7c)
extern "C" ARM unsigned int func_ov014_02186d7c(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    r4 = r0;
    r0 = *(unsigned char*)((char*)r4 + 0x17a);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { return r0; }
    r0 = *(unsigned int*)((char*)r4 + 0xc0);
    r0 = (unsigned int)_Z23ClearAllBuffers0207fcb8P11Obj0207fcb8(r0);
    r0 = *(unsigned int*)((char*)r4 + 0xc0);
    r0 = (unsigned int)_Z35CallFunc0204c8f0OverEntries0207fd00P11Obj0207fd00(r0);
    r1 = 0x1;
    r0 = *(unsigned int*)((char*)r4 + 0xc0);
    r3 = r1;
    r2 = 0x0;
    r0 = (unsigned int)func_0207fe80(r0, r1, r2, r3);
    r0 = *(unsigned int*)((char*)r4 + 0xc0);
    r0 = (unsigned int)_Z28CallFunc0204b04cOverList0x2cP12Cont0207fd44(r0);
    r0 = r4;
    r0 = (unsigned int)func_ov014_02186e2c(r0);
    return r0;
}
