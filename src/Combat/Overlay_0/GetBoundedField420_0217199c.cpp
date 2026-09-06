#include <globaldefs.h>

// USA: func_ov000_0217199c
ARM int GetBoundedField420_0217199c(void* obj, int index) {
    if (index < 0 || index >= 0x93) return 0;
    return *(int*)((char*)obj + 0x1a4 + (index << 2));
}
