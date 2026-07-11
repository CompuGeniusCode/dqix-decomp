#include <globaldefs.h>

// USA: func_020464dc
ARM void SetByte0x1880(void* obj, unsigned char value) {
    *((unsigned char*)obj + 0x1880) = value;
}
