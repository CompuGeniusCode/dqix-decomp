#include <globaldefs.h>

extern "C" unsigned int func_ov016_0218edac();

// USA: func_ov016_0218e7ec  (semantic: Trans_0218e7ec)
extern "C" ARM unsigned int func_ov016_0218e7ec(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    r4 = r0;
    r0 = (unsigned int)func_ov016_0218edac();
    r0 = r4;
    return r0;
}
