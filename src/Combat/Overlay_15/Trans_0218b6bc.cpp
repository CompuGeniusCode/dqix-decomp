#include <globaldefs.h>

extern int data_ov015_02194560;
extern "C" unsigned int _Z18InitList8_0218b9acP14List8_0218b9aci(unsigned int, unsigned int);
extern "C" unsigned int _ZNK6Script9Parameter5ToIntEv(unsigned int, unsigned int);

// USA: func_ov015_0218b6bc  (semantic: Trans_0218b6bc)
extern "C" ARM unsigned int func_ov015_0218b6bc(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r1 = (unsigned int)&data_ov015_02194560;
    r4 = *(unsigned int*)((char*)r1 + 0x0);
    r0 = (unsigned int)_ZNK6Script9Parameter5ToIntEv(r0, r1);
    r1 = r0;
    r0 = r4;
    r0 = (unsigned int)_Z18InitList8_0218b9acP14List8_0218b9aci(r0, r1);
    r0 = 0x1;
    return r0;
}
