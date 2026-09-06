#include <globaldefs.h>

struct ScaleVec_021f6b5c { int pad0[5]; float x; float y; float sx; float sy; };

// USA: func_ov024_021f6b5c
ARM int ScaleVectorBy0Point75_021f6b5c(struct ScaleVec_021f6b5c* obj) {
    obj->sx = obj->x * 0.75f;
    obj->sy = obj->y * 0.75f;
    return 1;
}
