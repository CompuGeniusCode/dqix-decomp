#include <globaldefs.h>

extern "C" unsigned int _Z15GetData02107930v();
extern "C" unsigned int _Z19GetActiveCombatWorkv();
extern "C" unsigned int _Z23RecordValueChangeAt0x20P22HalfwordRecord02052884ss(unsigned int, unsigned int, unsigned int);

// USA: func_ov025_021e74f4  (semantic: Trans_021e74f4)
extern "C" ARM unsigned int func_ov025_021e74f4(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)_Z15GetData02107930v();
    r1 = *(short*)((char*)r4 + 0x8);
    r2 = *(unsigned short*)((char*)r4 + 0xa);
    r0 = (unsigned int)_Z23RecordValueChangeAt0x20P22HalfwordRecord02052884ss(r0, r1, r2);
    r0 = (unsigned int)_Z19GetActiveCombatWorkv();
    r1 = r0 + 0x6000;
    r0 = 0x1;
    *(unsigned char*)((char*)r1 + 0xfd4) = (unsigned char)r0;
    return r0;
}
