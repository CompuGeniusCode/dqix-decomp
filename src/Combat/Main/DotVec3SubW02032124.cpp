#include <globaldefs.h>

struct FixedVec3 {
    int x;
    int y;
    int z;
};

struct VecW02032124 {
    struct FixedVec3 v;
    int w;
};

int DotFixedVec3(struct FixedVec3* a, struct FixedVec3* b);

// USA: func_02032124
ARM int DotVec3SubW02032124(struct FixedVec3* a, struct VecW02032124* b) {
    return DotFixedVec3(&b->v, a) - b->w;
}
