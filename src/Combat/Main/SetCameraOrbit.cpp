#include <globaldefs.h>

extern "C" int _Z22fix32ReduceAngle0To2Pii(int);
extern "C" int fix32_Sqrt(int value);

struct Vec3;
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);

struct Matrix43 { unsigned int elements[12]; };
extern "C" void _Z15RotationMatrixYi(struct Matrix43* outMatrix, int angle);

struct FixedVec3_2034;
struct FixedMtx3T_2034;
extern "C" void Mat4x3_ApplyToVector(struct FixedVec3_2034* vec, struct FixedMtx3T_2034* m, struct FixedVec3_2034* out);

static inline int FixedMulRound(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

struct Vec3Fx32 {
    int x;
    int y;
    int z;
};

// Places the camera on an orbit around its look-at point. Yaw, height and distance are kept at 0x70,
// 0x74 and 0x78, and the eye at 0x04 is recomputed as the target at 0x10 plus
// (0, height, sqrt(distance^2 - height^2)) turned about Y by the yaw. The arguments arrive in that
// order, so the second is the height above the target and the third the straight-line distance from
// it -- turning about Y leaves the vertical component alone, which is what makes the offset come out
// exactly the distance long. Every setter in the family re-calls this after clamping one of the
// three, which is why height is held at least 1.0 short of the distance, and func_0202ec5c re-calls
// it with all three read back out of the object after moving the target. The object is the one
// GetActiveCamera returns; its initialiser fills in the 20.12 aspect 0x1555 (256/192), a near plane
// of 1.0 and a far plane of 400.0.
extern "C" ARM void SetCameraOrbit(void* camera, int angleArg, int height, int distance) {
    int rotAngle;
    int heightSquared, distanceSquared, horizontalSquared;
    struct Vec3Fx32 eyeOffset;
    struct Matrix43 mtxCopy;
    struct Matrix43 mtx;

    rotAngle = _Z22fix32ReduceAngle0To2Pii(angleArg);
    *(int*)((char*)camera + 0x70) = rotAngle;
    *(int*)((char*)camera + 0x74) = height;
    *(int*)((char*)camera + 0x78) = distance;

    heightSquared = FixedMulRound(height, height);
    distanceSquared = FixedMulRound(distance, distance);
    horizontalSquared = distanceSquared - heightSquared;

    eyeOffset.x = 0;
    eyeOffset.y = height;
    eyeOffset.z = fix32_Sqrt(horizontalSquared);

    _Z15RotationMatrixYi(&mtx, rotAngle);
    mtxCopy = mtx;

    Mat4x3_ApplyToVector((struct FixedVec3_2034*)&eyeOffset, (struct FixedMtx3T_2034*)&mtxCopy, (struct FixedVec3_2034*)&eyeOffset);

    Vector3fix_Add((struct Vec3*)((char*)camera + 0x10), (struct Vec3*)&eyeOffset, (struct Vec3*)((char*)camera + 4));
}
