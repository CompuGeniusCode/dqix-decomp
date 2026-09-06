#include <globaldefs.h>

struct Obj3a8Timer_02159f94 {
    unsigned char pad0[0x3a4];
    int field3a4;
    int pad3a8;
    int unk3ac;
};

// USA: func_ov006_02159f94  (semantic: ClearField3acIfFlagSet_02159f94)
extern "C" ARM void func_ov006_02159f94(struct Obj3a8Timer_02159f94* obj) {
    if (obj->unk3ac != 0 && obj->field3a4 != 0) {
        obj->unk3ac = 0;
    }
}
