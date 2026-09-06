#include <globaldefs.h>

// USA: func_02039d58
ARM void ClearFlag0x1ceBit0x4(unsigned char* obj) {
    obj[0x1ce] &= ~4;
}
