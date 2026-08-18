#include <globaldefs.h>

struct MotionState02154d34 {
    char pad0[8];
    int base8;
    char pad2[4];
    int base10;
    char pad3[0x14];
    int f28;
    int f2c;
};

// USA: func_ov005_02154d34  (semantic: UpdateDeltaPosition_02154d34)
extern "C" ARM void func_ov005_02154d34(MotionState02154d34* obj, int a, int b) {
    obj->f28 = a + obj->base8;
    obj->f2c = b + obj->base10;
}
