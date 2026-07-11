#include <globaldefs.h>

struct U16Field0x6_020375f8 {
    char unk[0x6];
    unsigned short field;
};

// USA: func_020375f8
ARM unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj) {
    return obj->field;
}
