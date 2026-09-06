#include <globaldefs.h>

// USA: func_ov003_02159240
ARM void SetFlag8At_02159240(void* obj) {
    *((unsigned char*)obj + 0x59f) |= 0x8;
}
