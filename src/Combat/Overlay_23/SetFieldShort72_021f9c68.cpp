#include <globaldefs.h>

// USA: func_ov023_021f9c68
ARM void SetFieldShort72_021f9c68(void* obj, unsigned short value) {
    *(unsigned short*)((char*)obj + 0x48) = value;
}
