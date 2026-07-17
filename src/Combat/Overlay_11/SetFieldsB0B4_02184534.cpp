#include <globaldefs.h>

struct Obj_02184534 { char pad[0xb0]; int fieldB0; int fieldB4; };

// USA: func_ov011_02184534
ARM void SetFieldsB0B4_02184534(struct Obj_02184534* obj, int b0, int b4) {
    obj->fieldB0 = b0;
    obj->fieldB4 = b4;
}
