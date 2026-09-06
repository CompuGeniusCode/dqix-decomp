#include <globaldefs.h>

// USA: func_020de56c
ARM int GetField0x18Short(void* obj) {
    return *(short*)((char*)obj + 0x18);
}
