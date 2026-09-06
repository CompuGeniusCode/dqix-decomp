#include <globaldefs.h>

struct Fields020d5158 {
    unsigned char pad0[0x4];
    unsigned short f4;
    unsigned char pad1[0x12];
    unsigned short f18;
    unsigned char pad2[0x18];
    unsigned short f32;
};

// USA: func_020d5158
ARM int CheckFieldsInRange020d5158(struct Fields020d5158* o) {
    if (o->f4 > 0x70) return 0;
    if (o->f18 < 0xa || o->f18 > 0x3e8) return 0;
    if (o->f32 < 1) goto ret0;
    if (o->f32 <= 0xe) goto ret1;
ret0:
    return 0;
ret1:
    return 1;
}
