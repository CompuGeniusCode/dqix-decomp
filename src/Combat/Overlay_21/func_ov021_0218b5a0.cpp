#include <globaldefs.h>

extern "C" unsigned int _Z12Init0203aee0P15Struct_0203aee0();
extern "C" unsigned int _ZN13SafeAllocator21ResetAllocatorPointerEv(unsigned int);

// USA: func_ov021_0218b5a0  (semantic: Trans_0218b5a0)
extern "C" ARM unsigned int func_ov021_0218b5a0(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)_Z12Init0203aee0P15Struct_0203aee0();
    r0 = r4 + 0x2c;
    r0 = (unsigned int)_ZN13SafeAllocator21ResetAllocatorPointerEv(r0);
    r0 = 0x0;
    *(unsigned int*)((char*)r4 + 0x40) = (unsigned int)r0;
    *(unsigned int*)((char*)r4 + 0xb8) = (unsigned int)r0;
    return r0;
}
