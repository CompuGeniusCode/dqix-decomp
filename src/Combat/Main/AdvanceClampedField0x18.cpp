#include <globaldefs.h>

struct ClampField020ddffc {
    unsigned char pad0[4];
    unsigned char byte4;
    unsigned char pad5[0xf];
    int field14;
    int field18;
    unsigned char pad1c[4];
    int field20;
};

// USA: func_020ddffc
ARM void AdvanceClampedField0x18(struct ClampField020ddffc* obj) {
    obj->field18 = obj->field18 + obj->field20;
    if (obj->field14 < 0) {
        obj->field14 = obj->field14 + 1;
    }
    if (obj->field18 >= 0x1000) {
        obj->field18 = 0x1000;
        obj->byte4 = 3;
    }
}
