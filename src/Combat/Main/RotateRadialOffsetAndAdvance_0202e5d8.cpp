#include <globaldefs.h>

extern "C" int func_02030f30(int);
int HardwareSqrt(int value);

struct Vec3;
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);

struct Mtx43_02030d84 { unsigned int v[12]; };
void BuildRotationMatrixY(struct Mtx43_02030d84* dst, int angle);

struct FixedVec3_2034;
struct FixedMtx3T_2034;
void MulVec3MtxTranslate020c2034(struct FixedVec3_2034* v, struct FixedMtx3T_2034* m, struct FixedVec3_2034* out);

static inline int FixedMulRound_0202e5d8(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

struct Vec3Local_0202e5d8 {
    int x;
    int y;
    int z;
};

// USA: func_0202e5d8  (semantic: RotateRadialOffsetAndAdvance_0202e5d8)
extern "C" ARM void func_0202e5d8(void* obj, int angleArg, int radiusY, int heightZ) {
    int rotAngle;
    int sq1, sq2, diff;
    struct Vec3Local_0202e5d8 v;
    struct Mtx43_02030d84 mtxCopy;
    struct Mtx43_02030d84 mtx;

    rotAngle = func_02030f30(angleArg);
    *(int*)((char*)obj + 0x70) = rotAngle;
    *(int*)((char*)obj + 0x74) = radiusY;
    *(int*)((char*)obj + 0x78) = heightZ;

    sq1 = FixedMulRound_0202e5d8(radiusY, radiusY);
    sq2 = FixedMulRound_0202e5d8(heightZ, heightZ);
    diff = sq2 - sq1;

    v.x = 0;
    v.y = radiusY;
    v.z = HardwareSqrt(diff);

    BuildRotationMatrixY(&mtx, rotAngle);
    mtxCopy = mtx;

    MulVec3MtxTranslate020c2034((struct FixedVec3_2034*)&v, (struct FixedMtx3T_2034*)&mtxCopy, (struct FixedVec3_2034*)&v);

    AddVec3((struct Vec3*)((char*)obj + 0x10), (struct Vec3*)&v, (struct Vec3*)((char*)obj + 4));
}
