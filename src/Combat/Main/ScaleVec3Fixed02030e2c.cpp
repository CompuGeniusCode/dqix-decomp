#include <globaldefs.h>

struct Vec3Fixed02030e2c {
    int x;
    int y;
    int z;
};

// USA: func_02030e2c
ARM void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out) {
    out->x = (int)(((long long)in->x * scale + 0x800) >> 12);
    out->y = (int)(((long long)in->y * scale + 0x800) >> 12);
    out->z = (int)(((long long)in->z * scale + 0x800) >> 12);
}
