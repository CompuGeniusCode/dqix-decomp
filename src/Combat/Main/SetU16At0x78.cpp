#include <globaldefs.h>

struct U16Field0x78_02037600 {
    char unk[0x78];
    unsigned short field;
};

// USA: func_02037600
ARM void SetU16At0x78(struct U16Field0x78_02037600* obj, unsigned short value) {
    obj->field = value;
}
