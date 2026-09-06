#include <globaldefs.h>

struct MotionState02154d50 {
    char pad0[8];
    int base8;
    int basec;
    int base10;
    int base14;
    char pad4[8];
    int f20;
    int f24;
};

// USA: func_ov005_02154d50  (semantic: UpdateDeltaPosition_02154d50)
extern "C" ARM void func_ov005_02154d50(MotionState02154d50* obj, int a, int b) {
    obj->f20 = obj->basec + (a - obj->base8);
    obj->f24 = obj->base14 + (b - obj->base10);
}
