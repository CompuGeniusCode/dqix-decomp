#include <globaldefs.h>

struct FixedVec3 {
    int x;
    int y;
    int z;
};

// USA: func_020c2df8
extern "C" ARM int Vector3fix_InnerProduct(struct FixedVec3* a, struct FixedVec3* b) {
    long long acc = (long long)a->x * b->x + (long long)a->y * b->y + (long long)a->z * b->z;
    return (int)((acc + 0x800) >> 12);
}
