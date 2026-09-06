#include <globaldefs.h>
#pragma optimize_for_size off

// USA: func_ov000_02171b9c
ARM void* GetPointerField_02171b9c_02171b9c(void* obj, int idx) {
    if (idx < 0) goto fail;
    if (idx < 0x10) goto ok;
fail:
    return NULL;
ok:
    return *(void**)((char*)obj + idx * 4 + 0x3f0);
}
