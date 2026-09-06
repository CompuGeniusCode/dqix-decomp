#include <globaldefs.h>

struct ScaleVec_021f6dd4 { int pad0[5]; float x; float y; float sx; float sy; };

// USA: func_ov024_021f6dd4
ARM int ScaleVectorBy2_021f6dd4(struct ScaleVec_021f6dd4* obj) {
    obj->sx = obj->x * 2.0f;
    obj->sy = obj->y * 2.0f;
    return 1;
}
