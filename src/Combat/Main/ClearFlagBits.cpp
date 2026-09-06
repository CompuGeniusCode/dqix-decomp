#include <globaldefs.h>

// USA: func_020a28b0
ARM void ClearFlagBits(unsigned char* obj, int mask) {
    obj[0x244] &= ~mask;
}
