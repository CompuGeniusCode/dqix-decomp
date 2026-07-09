#include <globaldefs.h>

struct Sub02081ee4 {
    unsigned short field_0;
    unsigned char field_2;
};

struct Obj02081ee4 {
    struct Sub02081ee4 *field_0;
    unsigned short field_4;
    signed char field_6;
    signed char field_7;
    signed char field_8;
};

// USA: func_02081ee4
ARM void InitWithSub02081ee4(struct Obj02081ee4 *obj, struct Sub02081ee4 *sub) {
    obj->field_0 = 0;
    if (sub != NULL) {
        obj->field_0 = sub;
        sub->field_0 = 0;
        sub->field_2 = 0;
    }
    obj->field_4 = 0;
    obj->field_6 = 20;
    obj->field_7 = 10;
    obj->field_8 = obj->field_6;
}
