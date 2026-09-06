#include <globaldefs.h>

// USA: func_020177a8
ARM void* GetElementStride0x24(unsigned char* obj, int index) {
    if (index < 0 || obj[0x477] <= index) {
        return NULL;
    }
    return *(unsigned char**)(obj + 0x47c) + index * 0x24;
}
