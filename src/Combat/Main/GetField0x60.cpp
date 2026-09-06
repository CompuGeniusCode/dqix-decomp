#include <globaldefs.h>

struct StructF0x60_0203cdd0 {
    char pad[0x60];
    int field60;
};

// USA: func_0203cdd0
ARM int GetField0x60(struct StructF0x60_0203cdd0* obj) {
    return obj->field60;
}
