#include <globaldefs.h>

// USA: func_ov023_021e6198
ARM void SetIntC0C_021e6198(void* obj, int value) {
    *(int*)((char*)obj + 0xc0c) = value;
}
