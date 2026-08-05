#include <globaldefs.h>

extern "C" unsigned int _Z15GetBattleStructv();
extern "C" unsigned int _Z18GetField0x3b0ValueP12BattleStruct();
extern "C" unsigned int _Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(unsigned int, unsigned int, unsigned int);

// USA: func_ov025_021e8100  (semantic: Trans_021e8100)
extern "C" ARM unsigned int func_ov025_021e8100(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)_Z15GetBattleStructv();
    r0 = (unsigned int)_Z18GetField0x3b0ValueP12BattleStruct();
    cc = (int)(r0) - (int)(0x0);
    if (cc == 0) { goto L24; }
    r1 = *(short*)((char*)r4 + 0xa);
    r2 = *(unsigned short*)((char*)r4 + 0x8);
    r0 = (unsigned int)_Z33StoreFields0x1e4And0x1e8IfNonZeroPhii(r0, r1, r2);
L24:;
    r0 = 0x1;
    return r0;
}
