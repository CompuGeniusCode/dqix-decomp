#include <globaldefs.h>

struct FloatXYScale_021f6b28 { char pad[0x14]; float x; float y; float outX; float outY; };

// USA: func_ov024_021f6b28
ARM int ScaleXYBy1Point25_021f6b28(struct FloatXYScale_021f6b28* obj) {
    obj->outX = obj->x * 1.25f;
    obj->outY = obj->y * 1.25f;
    return 1;
}
