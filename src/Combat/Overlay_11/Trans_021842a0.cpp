#include <globaldefs.h>

extern "C" unsigned int _ZN13SafeAllocator21ResetAllocatorPointerEv(unsigned int, unsigned int);

// USA: func_ov011_021842a0  (semantic: Trans_021842a0)
extern "C" ARM unsigned int func_ov011_021842a0(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r1 = 0x0;
    r0 = r4 + 0x4;
    *(unsigned int*)((char*)r4 + 0x0) = (unsigned int)r1;
    r0 = (unsigned int)_ZN13SafeAllocator21ResetAllocatorPointerEv(r0, r1);
    r0 = 0x0;
    *(unsigned int*)((char*)r4 + 0x18) = (unsigned int)r0;
    *(unsigned int*)((char*)r4 + 0x1c) = (unsigned int)r0;
    return r0;
}
