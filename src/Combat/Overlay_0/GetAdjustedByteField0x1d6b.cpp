#include <globaldefs.h>

// USA: func_ov000_021815c8
ARM int GetAdjustedByteField0x1d6b(void* obj) {
    signed char val = *((signed char*)obj + 0x1d6b);
    if (val < 0) return -1;
    return *((signed char*)obj + val + 0x70);
}
