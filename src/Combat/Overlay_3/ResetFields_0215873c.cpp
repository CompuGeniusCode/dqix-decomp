#include <globaldefs.h>

// USA: func_ov003_0215873c
ARM void ResetFields_0215873c(void* obj) {
    *(int*)((char*)obj + 0x20c) = -1;
    *(int*)((char*)obj + 0x32c) = 0;
    *((unsigned char*)obj + 0x208) = 0;
}
