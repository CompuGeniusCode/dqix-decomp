#include <globaldefs.h>

struct FixedVec3 {
    int x;
    int y;
    int z;
};

static inline int FixedMulRound(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

// USA: func_02030fe4
ARM int FixedVec3DistanceSq(struct FixedVec3* a, struct FixedVec3* b) {
    int dx = a->x - b->x;
    int dy = a->y - b->y;
    int dz = a->z - b->z;
    int qy = FixedMulRound(dy, dy);
    int qx = FixedMulRound(dx, dx);
    int qz = FixedMulRound(dz, dz);
    return qx + qy + qz;
}
