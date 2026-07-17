#include <globaldefs.h>

// USA: func_ov023_021f9c90
ARM void SetFieldShort82_021f9c90(void* obj, unsigned short value) {
    *(unsigned short*)((char*)obj + 0x52) = value;
}
