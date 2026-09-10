#include <globaldefs.h>

extern "C" int _Z22fix32ReduceAngle0To2Pii(int);
extern "C" int fix32_Sqrt(int value);

struct Vec3;
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);

struct Mtx43_02030d84 { unsigned int v[12]; };
extern "C" void _Z15RotationMatrixYi(struct Mtx43_02030d84* dst, int angle);

struct FixedVec3_2034;
struct FixedMtx3T_2034;
extern "C" void Mat4x3_ApplyToVector(struct FixedVec3_2034* v, struct FixedMtx3T_2034* m, struct FixedVec3_2034* out);

static inline int FixedMulRound_0202e5d8(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

struct Vec3Local_0202e5d8 {
    int x;
    int y;
    int z;
};

// Places the camera on an orbit around its look-at point. Yaw, height and distance are kept at 0x70,
// 0x74 and 0x78, and the eye at 0x04 is recomputed as the target at 0x10 plus
// (0, height, sqrt(distance^2 - height^2)) turned about Y by the yaw. Every setter in the family
// re-calls this after clamping one of the three, which is why height is held at least 1.0 short of
// the distance. The object is the one GetActiveCamera returns; its initialiser fills in the 20.12
// aspect 0x1555 (256/192), a near plane of 1.0 and a far plane of 400.0.
extern "C" ARM void SetCameraOrbit(void* obj, int angleArg, int radiusY, int heightZ) {
    int rotAngle;
    int sq1, sq2, diff;
    struct Vec3Local_0202e5d8 v;
    struct Mtx43_02030d84 mtxCopy;
    struct Mtx43_02030d84 mtx;

    rotAngle = _Z22fix32ReduceAngle0To2Pii(angleArg);
    *(int*)((char*)obj + 0x70) = rotAngle;
    *(int*)((char*)obj + 0x74) = radiusY;
    *(int*)((char*)obj + 0x78) = heightZ;

    sq1 = FixedMulRound_0202e5d8(radiusY, radiusY);
    sq2 = FixedMulRound_0202e5d8(heightZ, heightZ);
    diff = sq2 - sq1;

    v.x = 0;
    v.y = radiusY;
    v.z = fix32_Sqrt(diff);

    _Z15RotationMatrixYi(&mtx, rotAngle);
    mtxCopy = mtx;

    Mat4x3_ApplyToVector((struct FixedVec3_2034*)&v, (struct FixedMtx3T_2034*)&mtxCopy, (struct FixedVec3_2034*)&v);

    Vector3fix_Add((struct Vec3*)((char*)obj + 0x10), (struct Vec3*)&v, (struct Vec3*)((char*)obj + 4));
}
