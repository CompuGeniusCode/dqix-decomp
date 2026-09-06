#include <globaldefs.h>

extern "C" unsigned int _Z25GetCombatantWithFlag0x800P12BattleStructi(unsigned int, unsigned int);
extern "C" unsigned int _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi(unsigned int, unsigned int, unsigned int);

// USA: func_ov017_021cbeec  (semantic: Trans_021cbeec)
extern "C" ARM unsigned int func_ov017_021cbeec(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    r4 = r1;
    r1 = *(signed char*)((char*)r4 + 0x4);
    r0 = r2;
    r0 = (unsigned int)_Z25GetCombatantWithFlag0x800P12BattleStructi(r0, r1);
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { return r0; }
    r1 = *(unsigned short*)((char*)r4 + 0x6);
    r2 = 0x1;
    r0 = (unsigned int)_Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi(r0, r1, r2);
    return r0;
}
