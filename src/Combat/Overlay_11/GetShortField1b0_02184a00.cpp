#include <globaldefs.h>

struct Obj_02184a00 { char pad[0x1b0]; unsigned short field1b0; };

// USA: func_ov011_02184a00
ARM unsigned short GetShortField1b0_02184a00(struct Obj_02184a00* obj) {
    return obj->field1b0;
}
