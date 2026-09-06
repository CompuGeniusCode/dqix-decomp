#include <globaldefs.h>

#pragma optimize_for_size off
// USA: func_ov017_0218d75c
ARM int HasNonZeroByteAtOfField498_0218d75c_0218d75c(void* obj) {
    void* p = *(void**)((char*)obj + 0x4498);
    return p != NULL && *(unsigned char*)((char*)p + 0x14) != 0;
}
