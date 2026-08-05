#include <globaldefs.h>


// USA: func_ov016_0218f330  (semantic: Trans_0218f330)
extern "C" ARM unsigned int func_ov016_0218f330(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r1 = *(unsigned int*)((char*)r0 + 0x90);
    r0 = r0 + (r1 << 2);
    r0 = *(unsigned int*)((char*)r0 + 0x88);
    return r0;
}
