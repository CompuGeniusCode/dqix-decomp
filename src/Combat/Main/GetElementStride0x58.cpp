#include <globaldefs.h>

// USA: func_0201e2d8
ARM void* GetElementStride0x58(unsigned char* obj, int index) {
    if (index < 0 || *(int*)(obj + 4) <= index) {
        return NULL;
    }
    return *(unsigned char**)obj + index * 0x58;
}
