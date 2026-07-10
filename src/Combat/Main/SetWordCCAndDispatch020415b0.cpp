#include <globaldefs.h>

extern "C" int func_02036e34(void*, int, int);

struct Obj020415b0 {
    char pad_00[0xcc];
    int field_cc;
    int field_d0;
};

// USA: func_020415b0
ARM int SetWordCCAndDispatch020415b0(struct Obj020415b0* obj, int value) {
    obj->field_cc = value;
    return func_02036e34(obj, value, obj->field_d0);
}
