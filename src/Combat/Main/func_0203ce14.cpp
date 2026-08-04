#include <globaldefs.h>

struct Vec3s32_020c3030 { int x; int y; int z; };
struct Vec3 { int x; int y; int z; };
struct Vec3Fixed02030e2c { int x; int y; int z; };
struct Struct_203cdd8 { char pad[0x64]; int value; };

int Distance3D020c3030(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);
void CopyVec3(int* dst, int* src);
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
ARM int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);
ARM void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);
extern "C" int func_020c338c(int x, int z);
void SetField0x64RoundedTo256(struct Struct_203cdd8* obj, int value);

// USA: func_0203ce14
extern "C" ARM void func_0203ce14(void* obj, struct Vec3s32_020c3030* target) {
    char* base = (char*)obj;
    int dist = Distance3D020c3030(target, (struct Vec3s32_020c3030*)(base + 0x4));
    if (dist == 0) {
        return;
    }
    CopyVec3((int*)(base + 0x78), (int*)target);
    int flags = *(int*)(base + 0x5c);
    flags |= 1;
    *(int*)(base + 0x5c) = flags;
    if (flags & 4) {
        return;
    }
    struct Vec3 diff;
    SubtractVec3((struct Vec3*)(base + 0x78), (struct Vec3*)(base + 0x4), &diff);
    int scale = HwDivideRounded020c2bf4(0x1000, dist);
    ScaleVec3Fixed02030e2c((struct Vec3Fixed02030e2c*)&diff, scale, (struct Vec3Fixed02030e2c*)&diff);
    int angle = func_020c338c(diff.x, diff.z);
    SetField0x64RoundedTo256((struct Struct_203cdd8*)obj, angle);
}
