#include <globaldefs.h>

// USA: func_020398a4
ARM void ClearFlag0x1ceBit0x1(unsigned char* obj) {
    obj[0x1ce] &= ~1;
}
