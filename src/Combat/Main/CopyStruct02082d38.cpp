#include <globaldefs.h>

struct Block02082d38 {
    unsigned char bytes[0x16];
};

struct Struct02082d38 {
    unsigned char arr[0x16];
    unsigned char field_16;
    unsigned char field_17;
};

// USA: func_02082d38
ARM void CopyStruct02082d38(struct Struct02082d38 *dst, struct Struct02082d38 *src) {
    *(struct Block02082d38*)dst->arr = *(struct Block02082d38*)src->arr;
    dst->field_16 = src->field_16;
    dst->field_17 = src->field_17;
}
