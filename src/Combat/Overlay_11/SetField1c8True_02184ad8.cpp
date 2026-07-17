#include <globaldefs.h>

struct Obj_02184ad8 { char pad[0x1c8]; int field1c8; };

// USA: func_ov011_02184ad8
ARM void SetField1c8True_02184ad8(struct Obj_02184ad8* obj) {
    obj->field1c8 = 1;
}
