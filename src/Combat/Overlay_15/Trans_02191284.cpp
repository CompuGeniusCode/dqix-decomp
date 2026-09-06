#include <globaldefs.h>


// USA: func_ov015_02191284  (semantic: Trans_02191284)
extern "C" ARM unsigned int func_ov015_02191284(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    r1 = *(short*)((char*)r0 + 0x60);
    r0 = *(short*)((char*)r0 + 0x5c);
    r0 = r1 - r0;
    return r0;
}
