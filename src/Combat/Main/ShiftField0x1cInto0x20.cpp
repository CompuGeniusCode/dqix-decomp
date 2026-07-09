#include <globaldefs.h>

struct S1a0 {
    char pad[0x1c];
    unsigned int f1c;
    unsigned int f20;
};

// USA: func_020371a0
ARM void ShiftField0x1cInto0x20(struct S1a0* obj, unsigned int v) {
    obj->f20 = obj->f1c;
    obj->f1c = v;
}
