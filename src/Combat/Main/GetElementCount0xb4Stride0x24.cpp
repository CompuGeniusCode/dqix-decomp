#include <globaldefs.h>

// USA: func_020d3d78
ARM void* GetElementCount0xb4Stride0x24(unsigned char* obj, int index) {
    if (index < *(int*)(obj + 0xb4)) {
        return obj + index * 0x24;
    }
    return NULL;
}
