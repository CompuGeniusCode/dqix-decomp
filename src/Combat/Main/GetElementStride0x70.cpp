#include <globaldefs.h>

// USA: func_0201e548
ARM void* GetElementStride0x70(unsigned char* obj, int index) {
    if (index < 0 || *(int*)(obj + 0x1c) <= index) {
        return NULL;
    }
    return *(unsigned char**)(obj + 0x18) + index * 0x70;
}
