#include <globaldefs.h>

// USA: func_020a298c
ARM void ClearFlag0x4At0x245(unsigned char* obj) {
    obj[0x245] &= ~0x4;
}
