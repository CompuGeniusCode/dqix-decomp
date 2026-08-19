#include <globaldefs.h>

extern "C" unsigned int func_02034bc4();

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0207a060
extern "C" ARM unsigned int _Z30ResetBattleParamsBlock0207a060Pv(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)func_02034bc4();
    r1 = 0x0;
    *(unsigned char*)((char*)r4 + 0xac) = (unsigned char)r1;
    r0 = 0x1000;
    *(unsigned int*)((char*)r4 + 0xcc) = (unsigned int)r0;
    *(unsigned int*)((char*)r4 + 0xd0) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0xd4) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0xd8) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0xdc) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0xe0) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0xe4) = (unsigned int)r1;
    *(unsigned short*)((char*)r4 + 0xf0) = (unsigned short)r1;
    r0 = 0x40000;
    *(unsigned int*)((char*)r4 + 0xe8) = (unsigned int)r0;
    *(unsigned int*)((char*)r4 + 0xec) = (unsigned int)r0;
    r0 = 0x1;
    *(unsigned char*)((char*)r4 + 0xf2) = (unsigned char)r0;
    *(unsigned char*)((char*)r4 + 0xf3) = (unsigned char)r0;
    *(unsigned int*)((char*)r4 + 0xf4) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0xf8) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0x100) = (unsigned int)r1;
    r0 = 0x1f;
    *(unsigned char*)((char*)r4 + 0xfc) = (unsigned char)r0;
    return r0;
}
