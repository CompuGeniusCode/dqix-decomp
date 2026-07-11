#include <globaldefs.h>

struct U16Field0x4_020347e0 {
    char unk[0x4];
    unsigned short field;
};

// USA: func_020347e0
ARM unsigned short GetU16At0x4(struct U16Field0x4_020347e0* obj) {
    return obj->field;
}
