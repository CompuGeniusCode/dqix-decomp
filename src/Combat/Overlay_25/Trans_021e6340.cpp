#include <globaldefs.h>

extern int data_02108760;
extern "C" unsigned int _Z19GetActiveCombatWorkv();
extern "C" unsigned int _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(unsigned int, unsigned int, unsigned int, unsigned int);

// USA: func_ov025_021e6340  (semantic: Trans_021e6340)
extern "C" ARM unsigned int func_ov025_021e6340(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)_Z19GetActiveCombatWorkv();
    r1 = r0 + 0x6f00;
    r3 = *(unsigned short*)((char*)r4 + 0x8);
    r0 = (unsigned int)&data_02108760;
    r2 = 0x0;
    *(unsigned short*)((char*)r1 + 0x4) = (unsigned short)r3;
    r1 = *(unsigned short*)((char*)r4 + 0x8);
    r0 = (unsigned int)_Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(r0, r1, r2, r3);
    r0 = 0x1;
    return r0;
}
