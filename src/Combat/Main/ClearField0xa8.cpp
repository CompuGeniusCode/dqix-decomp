#include <globaldefs.h>

// USA: func_02037b88
ARM void ClearField0xa8(void* obj) {
    *(int*)((char*)obj + 0xa8) = 0;
}
