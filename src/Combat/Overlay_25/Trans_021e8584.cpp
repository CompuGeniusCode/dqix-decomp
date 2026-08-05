#include <globaldefs.h>

extern "C" unsigned int _Z19GetActiveCombatWorkv();
extern "C" unsigned int _Z26SetTargetHalfwords0202e95cP23TargetHalfwords0202e95css(unsigned int, unsigned int, unsigned int);
extern "C" unsigned int func_ov000_02160f14();

// USA: func_ov025_021e8584  (semantic: Trans_021e8584)
extern "C" ARM unsigned int func_ov025_021e8584(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)_Z19GetActiveCombatWorkv();
    r0 = (unsigned int)func_ov000_02160f14();
    r1 = *(short*)((char*)r4 + 0x8);
    r2 = *(unsigned short*)((char*)r4 + 0xa);
    r0 = (unsigned int)_Z26SetTargetHalfwords0202e95cP23TargetHalfwords0202e95css(r0, r1, r2);
    r0 = 0x1;
    return r0;
}
