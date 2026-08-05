#include <globaldefs.h>

extern "C" unsigned int _Z19GetActiveCombatWorkv();
extern "C" unsigned int _Z20SetShortTriple0x6e44Pvttt(unsigned int, unsigned int, unsigned int, unsigned int);

// USA: func_ov025_021e821c  (semantic: Trans_021e821c)
extern "C" ARM unsigned int func_ov025_021e821c(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    unsigned int r6 = 0;
    r4 = *(short*)((char*)r0 + 0x8);
    r5 = *(unsigned short*)((char*)r0 + 0xa);
    r6 = *(unsigned short*)((char*)r0 + 0xc);
    r0 = (unsigned int)_Z19GetActiveCombatWorkv();
    r1 = r4;
    r2 = r5;
    r3 = r6;
    r0 = (unsigned int)_Z20SetShortTriple0x6e44Pvttt(r0, r1, r2, r3);
    r0 = 0x1;
    return r0;
}
