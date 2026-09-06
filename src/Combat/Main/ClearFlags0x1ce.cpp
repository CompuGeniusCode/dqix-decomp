#include <globaldefs.h>

// USA: func_020397ac
ARM void ClearFlags0x1ce(unsigned char* obj, unsigned int mask) {
    obj[0x1ce] &= ~mask;
}
