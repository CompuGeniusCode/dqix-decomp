#include <globaldefs.h>

struct Obj_02243690 {
    char pad[0x2c];
    signed char field2c;
};

typedef signed char (*StateFunc_02243690)(Obj_02243690*);
extern StateFunc_02243690 data_ov031_0224c8a8[];

// USA: func_ov031_02243690
ARM int RunStateTableEntry_02243690(Obj_02243690* obj) {
    if (obj->field2c >= 0) {
        obj->field2c = data_ov031_0224c8a8[obj->field2c](obj);
    }
    return 1;
}
