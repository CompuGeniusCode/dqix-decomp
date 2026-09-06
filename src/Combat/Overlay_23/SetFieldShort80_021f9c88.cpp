#include <globaldefs.h>

// USA: func_ov023_021f9c88
ARM void SetFieldShort80_021f9c88(void* obj, unsigned short value) {
    *(unsigned short*)((char*)obj + 0x50) = value;
}
