#include <globaldefs.h>

extern "C" char* func_ov017_0218b5b0(void);

// USA: func_ov025_021e86f0
ARM int SetFlag021e86f0(void) {
    char* p = func_ov017_0218b5b0() + 0x4000;
    p[0x48a] = 1;
    return 1;
}
