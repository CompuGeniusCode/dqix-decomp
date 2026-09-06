#include <globaldefs.h>

// USA: func_02039750
ARM int GetIntField0x260(void* obj) {
    return *(int*)((char*)obj + 0x260);
}
