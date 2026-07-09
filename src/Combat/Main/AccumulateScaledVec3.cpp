#include <globaldefs.h>

struct Vec3020B3B3C {
    int x;
    int y;
    int z;
};

#pragma optimize_for_size off
// USA: func_020b3b3c
ARM void AccumulateScaledVec3(struct Vec3020B3B3C* out, struct Vec3020B3B3C* src, int scalar, int addDirect) {
    if (addDirect != 0) {
        out->x += scalar;
        out->y += scalar;
        out->z += scalar;
    } else {
        out->x += (scalar * src->x) >> 12;
        out->y += (scalar * src->y) >> 12;
        out->z += (scalar * src->z) >> 12;
    }
}
