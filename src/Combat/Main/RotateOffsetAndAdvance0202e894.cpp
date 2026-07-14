#include <globaldefs.h>

struct Vec3;
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
void CopyVec3(int* dst, int* src);

struct Mtx43_02030d84 { unsigned int v[12]; };
void BuildRotationMatrixY(struct Mtx43_02030d84* dst, int angle);

struct FixedVec3_2034;
struct FixedMtx3T_2034;
void MulVec3MtxTranslate020c2034(struct FixedVec3_2034* v, struct FixedMtx3T_2034* m, struct FixedVec3_2034* out);

extern "C" void func_0202eab8(void* obj);

struct Vec3Storage0202e894 {
    unsigned int v[3];
};

// USA: func_0202e894
ARM void RotateOffsetAndAdvance0202e894(void* obj, int angle) {
    struct Vec3Storage0202e894 field4Copy;
    struct Vec3Storage0202e894 field10Copy;
    struct Mtx43_02030d84 builtMtx;
    struct Mtx43_02030d84 mtxCopy;
    struct Vec3Storage0202e894 diff;
    field4Copy = *(struct Vec3Storage0202e894*)((char*)obj + 0x4);
    field10Copy = *(struct Vec3Storage0202e894*)((char*)obj + 0x10);

    SubtractVec3((struct Vec3*)&field10Copy, (struct Vec3*)&field4Copy, (struct Vec3*)&diff);

    BuildRotationMatrixY(&builtMtx, angle);
    mtxCopy = builtMtx;

    MulVec3MtxTranslate020c2034((struct FixedVec3_2034*)&diff, (struct FixedMtx3T_2034*)&mtxCopy, (struct FixedVec3_2034*)&diff);

    AddVec3((struct Vec3*)&field4Copy, (struct Vec3*)&diff, (struct Vec3*)&field10Copy);

    CopyVec3((int*)((char*)obj + 0x10), (int*)&field10Copy);

    func_0202eab8(obj);
}
