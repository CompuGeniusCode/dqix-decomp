#include <globaldefs.h>

// USA: func_0201e664
ARM void* GetElementStride0x74(unsigned char* obj, int index) {
    if (index < 0 || *(int*)(obj + 0x28) <= index) {
        return NULL;
    }
    return *(unsigned char**)(obj + 0x24) + index * 0x74;
}
