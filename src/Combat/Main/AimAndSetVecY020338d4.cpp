#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void func_020c2f18(struct Vec3* a, struct Vec3* b);
extern "C" int func_020c338c(int x, int z);
extern "C" int func_02030f30(int angle);

struct Obj02033874;
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

struct Struct020338d4 {
    char pad[0x44];
    struct Vec3 vec; // 0x44
};

// USA: func_020338d4
ARM void AimAndSetVecY020338d4(struct Struct020338d4* self, struct Vec3* target) {
    struct Vec3 v;
    SubtractVec3(target, &self->vec, &v);
    func_020c2f18(&v, &v);
    int angle = func_02030f30(func_020c338c(v.x, v.z));
    SetVecYFromValue02033874((struct Obj02033874*)self, angle);
}
