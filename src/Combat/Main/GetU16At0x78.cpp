#include <globaldefs.h>

struct U16Field0x78_02037608 {
    char unk[0x78];
    unsigned short field;
};

// USA: func_02037608
ARM unsigned short GetU16At0x78(struct U16Field0x78_02037608* obj) {
    return obj->field;
}
