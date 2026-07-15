#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);

// USA: func_ov025_021e8708
ARM int ClearFlag_021e8708_021e8708(void) {
    *(unsigned char*)((char*)func_ov017_0218b5b0() + 0x4000 + 0x48a) = 0;
    return 1;
}
