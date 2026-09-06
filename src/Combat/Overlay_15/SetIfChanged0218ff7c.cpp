#include <globaldefs.h>

struct SetStruct_0218ff7c { char pad[0x1c]; unsigned char flag1c; char pad2[3]; int* arr20; char pad3[8]; unsigned char dirty2c; };

// USA: func_ov015_0218ff7c
ARM void SetIfChanged0218ff7c(struct SetStruct_0218ff7c* o, int idx, int val) {
    unsigned char f = o->flag1c;
    if (f != 0 && f != 1)
        return;
    if (val != o->arr20[idx]) {
        o->arr20[idx] = val;
        o->dirty2c = 1;
    }
}
