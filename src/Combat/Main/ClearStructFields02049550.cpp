#include <globaldefs.h>

struct StructFields02049550 {
    unsigned char field0;
    unsigned char field1;
    unsigned short field2;
    unsigned short field4;
    unsigned char field6;
};

// USA: func_02049550
ARM void ClearStructFields02049550(struct StructFields02049550* p) {
    p->field0 = 0;
    p->field1 = 0;
    p->field2 = 0;
    p->field4 = 0;
    p->field6 = 0;
}
