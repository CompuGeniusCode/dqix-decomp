#include <globaldefs.h>

struct Obj02034a30 {
    unsigned short field0;
    unsigned short field2;
    float field4;
};

// USA: func_02034a30  (semantic: AdjustAndScaleField0_02034a30)
extern "C" ARM float func_02034a30(struct Obj02034a30* obj, int param) {
    float a;
    float b;
    float sum;

    if (obj->field4 == 0.0f) {
        return (float)((unsigned int)obj->field0 * 31) / 65535.0f;
    }
    a = (float)((unsigned int)obj->field0 * 31) / 65535.0f;
    b = (float)((unsigned int)obj->field2 * 31) / 65535.0f;
    sum = a + obj->field4 * (float)param;
    if (0.0f < obj->field4 && b < sum) {
        sum = b;
        obj->field4 = 0.0f;
    } else if (obj->field4 < 0.0f && sum < b) {
        sum = b;
        obj->field4 = 0.0f;
    }
    obj->field0 = (unsigned short)(sum / 31.0f * 65535.0f);
    return sum;
}
