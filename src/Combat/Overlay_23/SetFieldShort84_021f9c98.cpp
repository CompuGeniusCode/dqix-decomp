#include <globaldefs.h>

// USA: func_ov023_021f9c98
ARM void SetFieldShort84_021f9c98(void* obj, unsigned short value) {
    *(unsigned short*)((char*)obj + 0x54) = value;
}
