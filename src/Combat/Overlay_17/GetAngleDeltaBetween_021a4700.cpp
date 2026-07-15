#include <globaldefs.h>

struct Vec3 { int x, y, z; };
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void func_020c2f18(struct Vec3* a, struct Vec3* b);
extern "C" int func_020c338c(int x, int z);
int WrapAngleDelta(int a, int b);

// USA: func_ov017_021a4700
ARM short GetAngleDeltaBetween_021a4700(struct Vec3* p0, int baseAngle, struct Vec3* p2) {
    struct Vec3 local;
    SubtractVec3(p2, p0, &local);
    func_020c2f18(&local, &local);
    int angle = func_020c338c(local.x, local.z);
    return (short)WrapAngleDelta(baseAngle, angle);
}
