#include <globaldefs.h>

// USA: func_02039758
ARM void SetIntField0x264(void* obj, int val) {
    *(int*)((char*)obj + 0x264) = val;
}
