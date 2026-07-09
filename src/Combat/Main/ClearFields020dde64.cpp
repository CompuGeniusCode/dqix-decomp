#include <globaldefs.h>

struct Fields020dde64 {
    unsigned char pad0[4];
    unsigned char byte4;
    unsigned char pad5[0xb];
    int field10;
    int field14;
    int field18;
    int field1c;
    unsigned char pad20[4];
    unsigned char byte24;
};

// USA: func_020dde64
ARM void ClearFields020dde64(struct Fields020dde64* obj) {
    obj->byte4 = 0;
    obj->field18 = 0;
    obj->field1c = 0;
    obj->field10 = 0;
    obj->field14 = 0;
    obj->byte24 = 0;
}
