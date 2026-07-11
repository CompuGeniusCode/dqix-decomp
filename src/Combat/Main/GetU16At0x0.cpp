#include <globaldefs.h>

struct U16Field0x0_020a8e80 {
    unsigned short field;
};

// USA: func_020a8e80
ARM unsigned short GetU16At0x0(struct U16Field0x0_020a8e80* obj) {
    return obj->field;
}
