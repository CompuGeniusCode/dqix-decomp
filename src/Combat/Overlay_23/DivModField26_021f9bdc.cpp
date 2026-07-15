#include <globaldefs.h>

struct Obj021f9bdc {
    char pad[0x26];
    unsigned short field26;
    unsigned short field28;
    unsigned short field2a;
};

// USA: func_ov023_021f9bdc
ARM void DivModField26_021f9bdc(struct Obj021f9bdc* o, int divisor) {
    o->field28 = divisor / o->field26;
    o->field2a = divisor % o->field26;
}
