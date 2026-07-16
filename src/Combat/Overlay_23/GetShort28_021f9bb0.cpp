#include <globaldefs.h>

struct Obj021f9bb0 {
    char pad[0x28];
    unsigned short field28;
};

// USA: func_ov023_021f9bb0
ARM unsigned int GetShort28_021f9bb0(struct Obj021f9bb0 *obj) {
    return obj->field28;
}
