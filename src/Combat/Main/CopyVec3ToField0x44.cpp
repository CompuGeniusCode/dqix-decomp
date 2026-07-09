#include <globaldefs.h>

struct Vec3_02059f38 {
    int x;
    int y;
    int z;
};

struct Target02059f38 {
    char unk0[0x44];
    int field44;
    int field48;
    int field4c;
};

// USA: func_02059f38
ARM void CopyVec3ToField0x44(struct Target02059f38* dst, struct Vec3_02059f38* src) {
    dst->field44 = src->x;
    dst->field48 = src->y;
    dst->field4c = src->z;
}
