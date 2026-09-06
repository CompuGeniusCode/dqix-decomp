#include <globaldefs.h>

struct Sub0208203c {
    unsigned short field_0;
    unsigned char field_2;
};

struct Obj0208203c {
    struct Sub0208203c *field_0;
    unsigned short field_4;
    signed char field_6;
    signed char field_7;
    signed char field_8;
};

// USA: func_0208203c
ARM void ResetWithSub0208203c(struct Obj0208203c *obj) {
    struct Sub0208203c *sub = obj->field_0;
    if (sub != NULL) {
        sub->field_0 = 0;
        sub->field_2 = 0;
    }
    obj->field_4 = 0;
    obj->field_8 = obj->field_6;
}
