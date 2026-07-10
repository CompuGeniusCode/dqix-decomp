#include <globaldefs.h>

int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);

struct Vec3_02030ef0 {
    int x;
    int y;
    int z;
};

// USA: func_02030ef0
ARM void DivideVec3Components02030ef0(struct Vec3_02030ef0* src, unsigned int a, struct Vec3_02030ef0* dst) {
    dst->x = HwDivideRounded020c2bf4(src->x, a);
    dst->y = HwDivideRounded020c2bf4(src->y, a);
    dst->z = HwDivideRounded020c2bf4(src->z, a);
}
