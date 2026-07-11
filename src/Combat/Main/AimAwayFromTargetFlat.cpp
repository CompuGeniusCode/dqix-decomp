#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void func_020c2f18(struct Vec3* a, struct Vec3* b);
extern "C" int func_020c338c(int x, int z);
extern "C" void func_02030f30(int angle);

// USA: func_02032424
ARM void AimAwayFromTargetFlat(struct Vec3* self, struct Vec3* target) {
    struct Vec3 v;
    SubtractVec3(target, self, &v);
    func_020c2f18(&v, &v);
    func_02030f30(func_020c338c(-v.x, -v.z));
}
