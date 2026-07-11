#include <globaldefs.h>

struct U16Field0x7a_02037610 {
    char unk[0x7a];
    unsigned short field;
};

// USA: func_02037610
ARM void SetU16At0x7a(struct U16Field0x7a_02037610* obj, unsigned short value) {
    obj->field = value;
}
