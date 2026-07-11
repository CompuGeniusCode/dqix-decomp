#include <globaldefs.h>

// USA: func_020b2f44
ARM void SetField0x2c(void* obj, int value) {
    *(int*)((char*)obj + 0x2c) = value;
}
