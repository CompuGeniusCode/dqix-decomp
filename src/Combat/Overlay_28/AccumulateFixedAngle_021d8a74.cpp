#include <globaldefs.h>

struct Accum_021d8a74 {
    int field0;
    char pad4[4];
    int field8;
};

// USA: func_ov028_021d8a74
ARM void AccumulateFixedAngle_021d8a74(Accum_021d8a74* obj, float angle) {
    obj->field0 = obj->field0 + (int)(2.0f * angle * 4096.0f);
    obj->field8 = obj->field8 + (int)(2.0f * angle * 4096.0f);
}
