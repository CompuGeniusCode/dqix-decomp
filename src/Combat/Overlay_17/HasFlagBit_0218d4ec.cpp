#include <globaldefs.h>

// USA: func_ov017_0218d4ec
ARM int HasFlagBit_0218d4ec(void* obj, int bit) {
    unsigned char* p = (unsigned char*)obj + 0x4331;
    return *p & (1 << bit);
}
