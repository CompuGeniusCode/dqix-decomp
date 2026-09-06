#include <globaldefs.h>

struct Obj020823e4 {
    unsigned int field_0;
    unsigned short field_4;
    unsigned short field_6;
    unsigned int field_8;
    unsigned int field_c;
    unsigned int field_10;
};

// USA: func_020823e4
ARM void CopyFiveFields020823e4(struct Obj020823e4 *dst, struct Obj020823e4 *src) {
    dst->field_0 = src->field_0;
    dst->field_4 = src->field_4;
    dst->field_8 = src->field_8;
    dst->field_c = src->field_c;
    dst->field_10 = src->field_10;
}
