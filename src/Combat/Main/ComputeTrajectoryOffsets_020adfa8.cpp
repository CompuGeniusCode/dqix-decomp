#include <globaldefs.h>

struct Vec3_020adfa8 { int x, y, z; };

short GetTableEntryOdd02030c9c(int x);
short GetTableEntryEven02030c68(int x);

struct Vec3s32_020c2f18;
extern "C" void func_020c2f18(struct Vec3s32_020c2f18* v, struct Vec3s32_020c2f18* out);

struct Vec3Target020ad1f0;
void SetVec3At0x0020ad1f0(struct Vec3Target020ad1f0* obj, int x, int y, int z);

struct Vec3Fixed02030e2c;
void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);

struct Vec3;
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);

void CopyVec3(int* dst, int* src);

struct ObjFields020adfa8 {
    char pad0[0x44];
    Vec3_020adfa8 f44;
    char pad50[0xae - 0x50];
    short fae;
    char padb0[0x164 - 0xb0];
    Vec3_020adfa8 f164;
    int f170;
    Vec3_020adfa8 f174;
    int f180;
};

// USA: func_020adfa8  (semantic: ComputeTrajectoryOffsets_020adfa8)
extern "C" ARM void func_020adfa8(ObjFields020adfa8* obj) {
    Vec3_020adfa8 v = obj->f44;
    int angle = obj->fae;
    Vec3_020adfa8 dir;
    int zval = GetTableEntryOdd02030c9c(angle);
    dir.x = GetTableEntryEven02030c68(angle);
    dir.y = 0;
    dir.z = zval;
    func_020c2f18((struct Vec3s32_020c2f18*)&dir, (struct Vec3s32_020c2f18*)&dir);
    Vec3_020adfa8 neg;
    SetVec3At0x0020ad1f0((struct Vec3Target020ad1f0*)&neg, -dir.x, -dir.y, -dir.z);
    Vec3_020adfa8 scaled;
    ScaleVec3Fixed02030e2c((struct Vec3Fixed02030e2c*)&neg, 0x1ccc, (struct Vec3Fixed02030e2c*)&scaled);
    Vec3_020adfa8 sum1;
    AddVec3((struct Vec3*)&v, (struct Vec3*)&scaled, (struct Vec3*)&sum1);
    CopyVec3((int*)&obj->f164, (int*)&sum1);
    Vec3_020adfa8 sum2;
    AddVec3((struct Vec3*)&sum1, (struct Vec3*)&scaled, (struct Vec3*)&sum2);
    CopyVec3((int*)&obj->f174, (int*)&sum2);
    obj->f170 = angle;
    obj->f180 = angle;
}
