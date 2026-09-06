#include <globaldefs.h>

struct Fields021849e0 { char pad[0x1b0]; unsigned short field1b0; char pad2[0x1c8-0x1b2]; int field1c8; };

// USA: func_ov011_021849e0
ARM void SetFieldConditional_021849e0(Fields021849e0* obj, unsigned short val) {
    if (obj->field1b0 != val) {
        obj->field1c8 = 1;
    }
    obj->field1b0 = val;
}
