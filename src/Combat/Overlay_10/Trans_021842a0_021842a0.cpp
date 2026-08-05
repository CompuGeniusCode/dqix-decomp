#include <globaldefs.h>

extern "C" unsigned int _Z23ResetListHeader020727d8P12List020727d8(unsigned int, unsigned int);
extern "C" unsigned int _ZN13SafeAllocator21ResetAllocatorPointerEv(unsigned int);

// USA: func_ov010_021842a0  (semantic: Trans_021842a0)
extern "C" ARM unsigned int func_ov010_021842a0(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = 0x0;
    *(unsigned char*)((char*)r4 + 0x0) = (unsigned char)r0;
    *(unsigned short*)((char*)r4 + 0x2) = (unsigned short)r0;
    r1 = r0 - 0x1;
    r0 = r4 + 0xc;
    *(unsigned int*)((char*)r4 + 0x4) = (unsigned int)r1;
    r0 = (unsigned int)_Z23ResetListHeader020727d8P12List020727d8(r0, r1);
    r0 = r4 + 0x14;
    r0 = (unsigned int)_ZN13SafeAllocator21ResetAllocatorPointerEv(r0);
    r0 = 0x0;
    *(unsigned char*)((char*)r4 + 0x1) = (unsigned char)r0;
    return r0;
}
