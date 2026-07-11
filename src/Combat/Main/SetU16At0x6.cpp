#include <globaldefs.h>

struct U16Field0x6_020375f0 {
    char unk[0x6];
    unsigned short field;
};

// USA: func_020375f0
ARM void SetU16At0x6(struct U16Field0x6_020375f0* obj, unsigned short v) {
    obj->field = v;
}
