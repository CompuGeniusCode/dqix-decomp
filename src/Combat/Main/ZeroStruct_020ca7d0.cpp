#include <globaldefs.h>

struct Vec3Words020ca7d0 {
    unsigned int a, b, c;
};

struct Struct020ca7d0 {
    Vec3Words020ca7d0 g0, g1, g2;
};

static const Vec3Words020ca7d0 kZeroVec3Words020ca7d0 = {0, 0, 0};

// SKIP attempt func_020ca7d0: target is a 3x-stmia zero-fill burst (mov r1,r2,r3=0 then
// 3x "stmia r0!,{r1,r2,r3}"); no C form found (memset call doesn't inline, struct-assign
// triggers hidden operator= helper / OVERGEN, element-wise stores don't merge into stm).
// Same idiom as InitStruct020c21dc.cpp, which needed hand asm. NOT a match, no // USA: tag.
THUMB void ZeroStruct_020ca7d0(Struct020ca7d0* obj) {
    obj->g0 = kZeroVec3Words020ca7d0;
    obj->g1 = kZeroVec3Words020ca7d0;
    obj->g2 = kZeroVec3Words020ca7d0;
}
