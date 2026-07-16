#include <globaldefs.h>

struct SetStruct_0219005c { char pad[0x1c]; unsigned char flag1c; char pad2[0xf]; unsigned char dirty2c; char pad3[0x13]; short field40; short field42; };

// USA: func_ov015_0219005c
ARM void SetPairIfChanged0219005c(struct SetStruct_0219005c* o, short v1, short v2) {
    unsigned char f = o->flag1c;
    if (f != 0 && f != 1)
        return;
    if (o->field42 != v1 || o->field40 != v2) {
        o->field42 = v1;
        o->field40 = v2;
        o->dirty2c = 2;
    }
}
