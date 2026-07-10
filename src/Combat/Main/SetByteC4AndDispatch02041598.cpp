#include <globaldefs.h>

extern "C" int func_020370a0(void*, unsigned char, int);

struct Obj02041598 {
    char pad_00[0xc4];
    char field_c4;
    char pad_c5[0xb];
    int field_d0;
};

// USA: func_02041598
ARM int SetByteC4AndDispatch02041598(struct Obj02041598* obj, int value) {
    obj->field_c4 = value;
    return func_020370a0(obj, value, obj->field_d0);
}
