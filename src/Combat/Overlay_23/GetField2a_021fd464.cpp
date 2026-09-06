#include <globaldefs.h>

struct Obj021fd464 {
    char pad[0x2a];
    unsigned short field2a;
};

// USA: func_ov023_021fd464
ARM unsigned int GetField2a_021fd464(struct Obj021fd464* o) {
    return o->field2a;
}
