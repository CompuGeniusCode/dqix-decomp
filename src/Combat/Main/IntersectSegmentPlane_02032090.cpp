#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
struct FixedVec3 { int x; int y; int z; };
struct Vec3Fixed02030e2c { int x; int y; int z; };
struct Plane02032090 { int x; int y; int z; int d; };

void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
int DotFixedVec3(struct FixedVec3* a, struct FixedVec3* b);
int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);
void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);

// USA: func_02032090  (semantic: IntersectSegmentPlane_02032090)
extern "C" ARM int func_02032090(struct Vec3* p0, struct Vec3* p1, struct Plane02032090* plane, int* outT, struct Vec3Fixed02030e2c* outPos) {
    struct Vec3 dir;
    int dot1, dot2;
    SubtractVec3(p1, p0, &dir);
    dot1 = DotFixedVec3((struct FixedVec3*)plane, (struct FixedVec3*)p0);
    dot2 = DotFixedVec3((struct FixedVec3*)plane, (struct FixedVec3*)&dir);
    *outT = HwDivideRounded020c2bf4(plane->d - dot1, dot2);
    if (*outT < 0) goto fail;
    if (*outT > 0x1000) goto fail;
    ScaleVec3Fixed02030e2c((struct Vec3Fixed02030e2c*)&dir, *outT, outPos);
    AddVec3((struct Vec3*)p0, (struct Vec3*)outPos, (struct Vec3*)outPos);
    return 1;
fail:
    return 0;
}
