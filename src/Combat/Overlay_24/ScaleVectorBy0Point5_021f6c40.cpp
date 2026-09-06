#include <globaldefs.h>

struct ScaleVec_021f6c40 { int pad0[5]; float x; float y; float sx; float sy; };

// USA: func_ov024_021f6c40
ARM int ScaleVectorBy0Point5_021f6c40(struct ScaleVec_021f6c40* obj) {
    obj->sx = obj->x * 0.5f;
    obj->sy = obj->y * 0.5f;
    return 1;
}
