#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
struct FixedVec3 { int x; int y; int z; };
struct Vec3s32_020c3030 { int x; int y; int z; };
struct Vec3Fixed02030e2c { int x; int y; int z; };

void CopyVec3(int* dst, int* src);
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
void AddVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);
int DotFixedVec3(struct FixedVec3* a, struct FixedVec3* b);
int Distance3D020c3030(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);
void ScaleVec3Fixed02030e2c(struct Vec3Fixed02030e2c* in, int scale, struct Vec3Fixed02030e2c* out);
int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);

// USA: func_02031468
ARM int ClosestPointOnSegment02031468(struct Vec3* a, struct Vec3* b, struct Vec3* p, struct Vec3* out) {
    int distAB = Distance3D020c3030((struct Vec3s32_020c3030*)a, (struct Vec3s32_020c3030*)b);
    int distAP = Distance3D020c3030((struct Vec3s32_020c3030*)a, (struct Vec3s32_020c3030*)p);
    if (distAB == 0) {
        CopyVec3((int*)out, (int*)p);
        return distAP;
    }
    if (distAP == 0) {
        CopyVec3((int*)out, (int*)p);
        return 0;
    }
    struct Vec3 dirAB;
    struct Vec3 dirAP;
    SubtractVec3(b, a, &dirAB);
    int scaleAB = HwDivideRounded020c2bf4(0x1000, distAB);
    ScaleVec3Fixed02030e2c((struct Vec3Fixed02030e2c*)&dirAB, scaleAB, (struct Vec3Fixed02030e2c*)&dirAB);
    SubtractVec3(p, a, &dirAP);
    int scaleAP = HwDivideRounded020c2bf4(0x1000, distAP);
    ScaleVec3Fixed02030e2c((struct Vec3Fixed02030e2c*)&dirAP, scaleAP, (struct Vec3Fixed02030e2c*)&dirAP);
    int dot = DotFixedVec3((struct FixedVec3*)&dirAB, (struct FixedVec3*)&dirAP);
    if (dot <= 0) {
        CopyVec3((int*)out, (int*)a);
        return distAP;
    }
    int projLen = (int)(((long long)distAP * dot + 0x800) >> 12);
    if (distAB < projLen) {
        CopyVec3((int*)out, (int*)b);
        return Distance3D020c3030((struct Vec3s32_020c3030*)p, (struct Vec3s32_020c3030*)b);
    }
    ScaleVec3Fixed02030e2c((struct Vec3Fixed02030e2c*)&dirAB, projLen, (struct Vec3Fixed02030e2c*)out);
    AddVec3(out, a, out);
    return Distance3D020c3030((struct Vec3s32_020c3030*)p, (struct Vec3s32_020c3030*)out);
}
