#include <globaldefs.h>

// USA: func_ov017_021b1fc0
ARM void* GetOffsetPtrromField_021b1fc0_021b1fc0(void* obj) {
    void* p = *(void**)((char*)obj + 0x24);
    return p ? (char*)p + 0x50 : NULL;
}
