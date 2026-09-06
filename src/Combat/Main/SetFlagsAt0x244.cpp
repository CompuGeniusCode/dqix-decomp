#include <globaldefs.h>

// USA: func_020a28a0
ARM void SetFlagsAt0x244(unsigned char* obj, unsigned char mask) {
    obj[0x244] |= mask;
}
