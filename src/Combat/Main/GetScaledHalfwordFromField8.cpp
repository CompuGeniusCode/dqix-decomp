#include <globaldefs.h>

struct SubHalf02035544 {
    unsigned char pad0[4];
    unsigned short field4;
};
struct Obj02035544 {
    unsigned char pad0[8];
    struct SubHalf02035544* field8;
};

// USA: func_02035544
ARM int GetScaledHalfwordFromField8(struct Obj02035544* obj) {
    return obj->field8->field4 << 12;
}
