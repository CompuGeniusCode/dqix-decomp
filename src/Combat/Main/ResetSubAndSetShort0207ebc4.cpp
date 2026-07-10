#include <globaldefs.h>

extern "C" void func_020b732c(void*);

struct Obj0207ebc4 {
    char unk[0x54];
    void* field_54;
    char unk2[0x4a];
    short field_a2;
};

// USA: func_0207ebc4
ARM void ResetSubAndSetShort0207ebc4(struct Obj0207ebc4* obj, short val) {
    if (obj->field_54 == NULL) return;
    func_020b732c(obj->field_54);
    obj->field_a2 = val;
}
