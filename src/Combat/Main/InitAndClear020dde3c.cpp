#include <globaldefs.h>

struct Fields020dde64;
ARM void ClearFields020dde64(struct Fields020dde64* obj);

struct InitStruct020dde3c {
    unsigned short field0;
    unsigned short field2;
    unsigned char pad4[4];
    int field8;
    int fieldc;
    unsigned char pad10[0x10];
    int field20;
};

// USA: func_020dde3c
ARM void InitAndClear020dde3c(struct InitStruct020dde3c* obj) {
    obj->field8 = 0;
    obj->fieldc = 0;
    obj->field0 = 0;
    obj->field2 = 0;
    obj->field20 = 0x51;
    ClearFields020dde64((struct Fields020dde64*)obj);
}
