#include <globaldefs.h>

// USA: func_02053ec8
ARM void SetField0x158(void* obj, int value) {
    *(int*)((char*)obj + 0x158) = value;
}
