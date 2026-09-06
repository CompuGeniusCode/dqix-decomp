#include <globaldefs.h>

extern "C" unsigned int _ZN13SafeAllocator21ResetAllocatorPointerEv(unsigned int);
extern "C" unsigned int _ZN8Object3D10InitializeEv(unsigned int, unsigned int);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02046e08
extern "C" ARM unsigned int _Z25InitBattleContext02046e08P11Obj02046e08(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r1 = 0x0;
    *(unsigned int*)((char*)r4 + 0x0) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0x4) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0x20) = (unsigned int)r1;
    r0 = 0x41700000;
    *(unsigned int*)((char*)r4 + 0x8) = (unsigned int)r1;
    *(unsigned int*)((char*)r4 + 0xc) = (unsigned int)r0;
    r0 = r1 - 0x1;
    *(unsigned int*)((char*)r4 + 0xec) = (unsigned int)r0;
    r1 = 0x1;
    *(unsigned char*)((char*)r4 + 0x1c) = (unsigned char)r1;
    r0 = r4 + 0x3c;
    *(unsigned char*)((char*)r4 + 0x1d) = (unsigned char)r1;
    r0 = (unsigned int)_ZN8Object3D10InitializeEv(r0, r1);
    r0 = r4 + 0x24;
    r0 = (unsigned int)_ZN13SafeAllocator21ResetAllocatorPointerEv(r0);
    r0 = 0x0;
    *(unsigned int*)((char*)r4 + 0x38) = (unsigned int)r0;
    *(unsigned int*)((char*)r4 + 0xe8) = (unsigned int)r0;
    *(unsigned int*)((char*)r4 + 0x10) = (unsigned int)r0;
    *(unsigned int*)((char*)r4 + 0x14) = (unsigned int)r0;
    *(unsigned int*)((char*)r4 + 0x18) = (unsigned int)r0;
    return r0;
}
