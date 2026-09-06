#include <globaldefs.h>

// USA: func_020a27a0
ARM void SetField0x238False(void* obj) {
    *(int*)((char*)obj + 0x238) = 0;
}
