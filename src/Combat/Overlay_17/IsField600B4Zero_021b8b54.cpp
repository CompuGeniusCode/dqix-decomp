#include <globaldefs.h>

// USA: func_ov017_021b8b54
ARM int IsField600B4Zero_021b8b54(void* obj) {
    unsigned short v = *(unsigned short*)((char*)obj + 0x600 + 0xb4);
    return v == 0 ? 1 : 0;
}
