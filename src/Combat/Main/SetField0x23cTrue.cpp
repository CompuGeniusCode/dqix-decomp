#include <globaldefs.h>

// USA: func_020a27ac
ARM void SetField0x23cTrue(void* obj) {
    *(int*)((char*)obj + 0x23c) = 1;
}
