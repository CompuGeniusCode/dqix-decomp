#include <globaldefs.h>

struct Vec3s02030fc8 {
    signed short x;
    signed short y;
    signed short z;
};

// USA: func_02030fc8
ARM void CopyVec3s_02030fc8(struct Vec3s02030fc8* dst, struct Vec3s02030fc8* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
