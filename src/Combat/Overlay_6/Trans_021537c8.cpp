#include <globaldefs.h>


// USA: func_ov006_021537c8  (semantic: Trans_021537c8)
extern "C" ARM unsigned int func_ov006_021537c8(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    *(unsigned int*)((char*)r0 + 0x4) = r1;
    *(unsigned int*)((char*)r0 + 0x8) = r2;
    *(unsigned int*)((char*)r0 + 0xc) = r3;
    return r0;
}
