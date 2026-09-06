#include <globaldefs.h>

struct Struct_020401e4 {
    int field0;
    unsigned char field4;
    unsigned char field5;
    unsigned char unk6[2];
    int field8;
};

// USA: func_020401e4
ARM void ClearStruct020401e4(struct Struct_020401e4* obj) {
    obj->field8 = 0;
    obj->field0 = 0;
    obj->field4 = 0;
    obj->field5 = 0;
}
