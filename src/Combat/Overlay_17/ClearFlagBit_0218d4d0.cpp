#include <globaldefs.h>

// USA: func_ov017_0218d4d0
ARM void ClearFlagBit_0218d4d0(void* obj, int bit) {
    unsigned char* p = (unsigned char*)obj + 0x4331;
    *p &= ~(1 << bit);
}
