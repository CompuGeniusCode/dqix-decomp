#include <globaldefs.h>

struct Obj021f9bc0 {
    char pad[0x26];
    unsigned short field26;
    unsigned short field28;
    unsigned short field2a;
};

// USA: func_ov023_021f9bc0
ARM unsigned short GetField2a_021f9bc0(struct Obj021f9bc0* o) {
    return o->field2a;
}
