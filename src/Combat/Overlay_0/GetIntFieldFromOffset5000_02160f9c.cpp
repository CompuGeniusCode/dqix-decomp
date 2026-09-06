#include <globaldefs.h>

// USA: func_ov000_02160f9c
ARM int GetIntFieldFromOffset5000_02160f9c(void* obj) {
    return *(int*)((char*)obj + 0x5000 + 0x5d8);
}
