#include <globaldefs.h>

struct Vec3 { int x, y, z; };

void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void func_020c2f18(struct Vec3* a, struct Vec3* b);
extern "C" int func_020c338c(int x, int z);
extern "C" int func_02030f30(int angle);
struct Vec3s32_020c3030;
int Distance3D020c3030(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

struct Obj0202ea4c {
    char pad0[4];
    struct Vec3 posA;
    struct Vec3 posB;
    char pad1[0x70 - 0x1c];
    int angle;
    int heightDelta;
    int distance;
};

// USA: func_0202ea4c
ARM void ComputeAngleHeightDistance0202ea4c(struct Obj0202ea4c* obj) {
    struct Vec3 v;
    SubtractVec3(&obj->posA, &obj->posB, &v);
    v.y = 0;
    func_020c2f18(&v, &v);
    obj->angle = func_02030f30(func_020c338c(v.x, v.z));
    obj->heightDelta = obj->posA.y - obj->posB.y;
    obj->distance = Distance3D020c3030((struct Vec3s32_020c3030*)&obj->posA, (struct Vec3s32_020c3030*)&obj->posB);
}
