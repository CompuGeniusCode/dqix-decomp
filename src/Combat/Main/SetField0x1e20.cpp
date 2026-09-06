#include <globaldefs.h>

// USA: func_02042b10
ARM void SetField0x1e20(void* obj, void* value) {
    *(void**)((char*)obj + 0x1e20) = value;
}
