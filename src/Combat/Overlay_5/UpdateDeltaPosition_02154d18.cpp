#include <globaldefs.h>

struct MotionState02154d18 {
    char pad0[8];
    int base8;
    char pad2[4];
    int base10;
    char pad3[4];
    int f18;
    int f1c;
};

// USA: func_ov005_02154d18  (semantic: UpdateDeltaPosition_02154d18)
extern "C" ARM void func_ov005_02154d18(MotionState02154d18* obj, int a, int b) {
    obj->f18 = a + obj->base8;
    obj->f1c = b + obj->base10;
}
