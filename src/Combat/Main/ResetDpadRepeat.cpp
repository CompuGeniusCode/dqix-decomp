#include <globaldefs.h>

struct Sub0208203c {
    unsigned short field_0;
    unsigned char field_2;
};

struct Obj0208203c {
    struct Sub0208203c *field_0;
    unsigned short field_4;
    signed char field_6;
    signed char field_7;
    signed char field_8;
};

// Rearms directional auto-repeat: the latched direction halfword and the state byte in the shared
// sub-record at +0x0 are cleared, the accumulator at +0x4 is zeroed, and the counter at +0x8 is
// reloaded from the initial delay at +0x6. func_02081f20 above drives the other side, latching one of
// the KEYINPUT direction bits {0x40, 0x80, 0x20, 0x10} on a fresh press, counting +0x8 down by the
// frame delta and adding the repeat interval at +0x7 when it goes negative, then calling this on
// release. Callers are almost all menu code: ov003 74, ov006 41, ov014 4, ov017 2, main 1.
extern "C" ARM void ResetDpadRepeat(struct Obj0208203c *obj) {
    struct Sub0208203c *sub = obj->field_0;
    if (sub != NULL) {
        sub->field_0 = 0;
        sub->field_2 = 0;
    }
    obj->field_4 = 0;
    obj->field_8 = obj->field_6;
}
