#include <globaldefs.h>

struct Obj021f6f08 {
    char pad[0x6];
    unsigned short field6;
};

// USA: func_ov023_021f6f08
ARM unsigned int GetShort6_021f6f08(struct Obj021f6f08 *obj) {
    return obj->field6;
}
