#include <globaldefs.h>

// USA: func_ov011_021849ac
ARM void SetFlags114_021849ac(void* obj, unsigned int mask) {
    *(unsigned int*)((char*)obj + 0x114) |= mask;
}
