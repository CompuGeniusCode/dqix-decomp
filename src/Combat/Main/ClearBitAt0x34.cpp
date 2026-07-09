#include <globaldefs.h>

// USA: func_020a367c
ARM void ClearBitAt0x34(unsigned char* obj, int index) {
    obj[0x34] &= ~(1 << index);
}
