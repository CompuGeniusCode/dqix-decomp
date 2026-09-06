#include <globaldefs.h>

struct Obj021f9eb4 {
    unsigned short field0;
    unsigned char field2;
    unsigned char field3;
};

// USA: func_ov023_021f9eb4
ARM void ClearFields0To3_021f9eb4(struct Obj021f9eb4* o) {
    o->field0 = 0;
    o->field2 = 0;
    o->field3 = 0;
}
