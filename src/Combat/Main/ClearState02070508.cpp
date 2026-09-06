#include <globaldefs.h>

struct State02070508 {
    unsigned char active;
    unsigned char pad[0xB];
    int field0xc;
    int field0x10;
};

// USA: func_02070508
ARM void ClearState02070508(struct State02070508 *obj) {
    obj->active = 0;
    obj->field0xc = 0;
    obj->field0x10 = 0;
}
