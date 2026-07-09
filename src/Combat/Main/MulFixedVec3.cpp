#include <globaldefs.h>

struct FixedVec3 {
    int x;
    int y;
    int z;
};

// USA: func_02030e88
ARM void MulFixedVec3(struct FixedVec3* a, struct FixedVec3* b, struct FixedVec3* out) {
    out->x = (int)(((long long)a->x * b->x + 0x800) >> 12);
    out->y = (int)(((long long)a->y * b->y + 0x800) >> 12);
    out->z = (int)(((long long)a->z * b->z + 0x800) >> 12);
}
