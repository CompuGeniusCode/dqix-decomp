#include <globaldefs.h>

struct ScaleVec_021f71a8 { int pad0[5]; float x; float y; float sx; float sy; };

// USA: func_ov024_021f71a8
ARM int ScaleVectorBy1Point5_021f71a8(struct ScaleVec_021f71a8* obj) {
    obj->sx = obj->x * 1.5f;
    obj->sy = obj->y * 1.5f;
    return 1;
}
