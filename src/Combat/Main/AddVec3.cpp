#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

// USA: func_020c2d90
extern "C" ARM void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out) {
    out->x = a->x + b->x;
    out->y = a->y + b->y;
    out->z = a->z + b->z;
}
