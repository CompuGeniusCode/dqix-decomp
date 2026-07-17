#include <globaldefs.h>

// USA: func_ov023_021f7188
ARM void SetFieldA8_021f7188(void* obj, unsigned short value) {
    *(unsigned short*)((char*)obj + 0xa8) = value;
}
