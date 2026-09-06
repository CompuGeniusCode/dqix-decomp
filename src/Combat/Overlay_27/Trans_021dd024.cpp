#include <globaldefs.h>

extern int data_ov027_021e33e0;

// USA: func_ov027_021dd024  (semantic: Trans_021dd024)
extern "C" ARM unsigned int func_ov027_021dd024(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r0 = (unsigned int)&data_ov027_021e33e0;
    r0 = *(unsigned int*)((char*)r0 + 0x8);
    r0 = *(unsigned int*)((char*)r0 + 0x8);
    return r0;
}
