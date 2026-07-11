#include <globaldefs.h>

// USA: func_0201e838
ARM void* GetPointerFromArray0x3c(unsigned char* obj, unsigned int index) {
    return *(void**)(obj + index * 4 + 0x3c);
}
