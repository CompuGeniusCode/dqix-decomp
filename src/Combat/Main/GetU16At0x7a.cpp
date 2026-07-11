#include <globaldefs.h>

struct U16Field0x7a_02037618 {
    char unk[0x7a];
    unsigned short field;
};

// USA: func_02037618
ARM unsigned short GetU16At0x7a(struct U16Field0x7a_02037618* obj) {
    return obj->field;
}
