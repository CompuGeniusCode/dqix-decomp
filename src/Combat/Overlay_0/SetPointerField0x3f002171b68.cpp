#include <globaldefs.h>

extern "C" int func_ov000_02171bc0(void*);

// USA: func_ov000_02171b68
ARM void SetPointerField0x3f002171b68(void* obj, int idx, void* val) {
    if (idx < 0) return;
    if (idx >= 0x10) return;
    if (val == 0) return;
    *(void**)((char*)obj + idx * 4 + 0x3f0) = val;
    *(unsigned char*)((char*)obj + 0x86) = (unsigned char)func_ov000_02171bc0(obj);
}
