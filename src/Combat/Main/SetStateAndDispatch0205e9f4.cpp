#include <globaldefs.h>

extern "C" void func_0205e944(void*, int);

struct Obj0205e9f4 {
    char pad_00[0xc8];
    int field_c8;
    unsigned char field_cc;
};

// USA: func_0205e9f4
ARM void SetStateAndDispatch0205e9f4(struct Obj0205e9f4* obj, int state) {
    if (state < 1) return;
    if (state > 5) return;
    obj->field_cc = (unsigned char)state;
    func_0205e944(obj, obj->field_c8);
}
