#include <globaldefs.h>

extern "C" int _ZN8Object3D24MaybeSetRegularAnimationEPKci(void*, int, int);

struct Obj020415b0 {
    char pad_00[0xcc];
    int field_cc;
    int field_d0;
};

// USA: func_020415b0
ARM int SetWordCCAndDispatch020415b0(struct Obj020415b0* obj, int value) {
    obj->field_cc = value;
    return _ZN8Object3D24MaybeSetRegularAnimationEPKci(obj, value, obj->field_d0);
}
