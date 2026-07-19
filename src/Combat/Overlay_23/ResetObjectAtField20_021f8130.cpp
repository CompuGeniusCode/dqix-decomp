#include <globaldefs.h>

struct Obj0204c754;
void ResetObject0204c754(struct Obj0204c754* obj);

// USA: func_ov023_021f8130
ARM void ResetObjectAtField20_021f8130(void* obj) {
    ResetObject0204c754((struct Obj0204c754*)((char*)obj + 0x20));
}
