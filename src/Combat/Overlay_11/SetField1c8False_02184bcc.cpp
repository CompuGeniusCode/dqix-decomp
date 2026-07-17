#include <globaldefs.h>

struct Obj_02184bcc { char pad[0x1c8]; int field1c8; };

// USA: func_ov011_02184bcc
ARM void SetField1c8False_02184bcc(struct Obj_02184bcc* obj) {
    obj->field1c8 = 0;
}
