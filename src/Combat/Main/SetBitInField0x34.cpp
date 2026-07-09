#include <globaldefs.h>

// USA: func_020a35cc
ARM void SetBitInField0x34(unsigned char* obj, int index) {
    obj[0x34] |= 1 << index;
}
