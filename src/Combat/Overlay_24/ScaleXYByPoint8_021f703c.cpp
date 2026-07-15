#include <globaldefs.h>

struct FloatXYScale_021f703c { char pad[0x14]; float x; float y; float outX; float outY; };

// USA: func_ov024_021f703c
ARM int ScaleXYByPoint8_021f703c(struct FloatXYScale_021f703c* obj) {
    obj->outX = obj->x * 0.8f;
    obj->outY = obj->y * 0.8f;
    return 1;
}
