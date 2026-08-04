#include <globaldefs.h>

struct Obj02034b34 {
    unsigned short field0;
    unsigned short field2;
    float field4;
};

// USA: func_02034b34
extern "C" ARM void func_02034b34(struct Obj02034b34* obj, int b, int c) {
    float a = (float)((unsigned int)obj->field0 * 31) / 65535.0f;
    float fb = (float)b;
    obj->field2 = (unsigned int)(65535.0f * (fb / 31.0f));
    if (c > 0) {
        obj->field4 = (fb - a) / (float)c;
    } else {
        obj->field4 = 0.0f;
    }
}
