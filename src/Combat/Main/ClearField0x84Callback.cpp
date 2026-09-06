#include <globaldefs.h>

// USA: func_020bd8fc
ARM void ClearField0x84Callback(void*, void*, void* obj) {
    *(int*)((char*)obj + 0x84) = 0;
}
