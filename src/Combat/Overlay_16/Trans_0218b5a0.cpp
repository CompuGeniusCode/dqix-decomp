#include <globaldefs.h>

extern "C" unsigned int _ZN13SafeAllocator21ResetAllocatorPointerEv();
extern "C" unsigned int func_02029568(unsigned int);

// USA: func_ov016_0218b5a0  (semantic: Trans_0218b5a0)
extern "C" ARM unsigned int func_ov016_0218b5a0(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)_ZN13SafeAllocator21ResetAllocatorPointerEv();
    r0 = r4 + 0x14;
    r0 = (unsigned int)func_02029568(r0);
    r0 = 0x1;
    *(unsigned int*)((char*)r4 + 0x94) = (unsigned int)r0;
    return r0;
}
