#include <globaldefs.h>

struct Vec3 { int x; int y; int z; };
void SubtractVec3(struct Vec3* a, struct Vec3* b, struct Vec3* out);

void CrossProductFixed020c2e34(int* a, int* b, int* out);

struct FixedVec3 { int x; int y; int z; };
int DotFixedVec3(struct FixedVec3* a, struct FixedVec3* b);

int HwDivideRounded020c2bf4(unsigned int numerHi, unsigned int denomLo);

// USA: func_02031b84
ARM int TestSweptTriangleBarycentric02031b84(struct Vec3* p0, struct Vec3* p1, struct Vec3* p2, struct Vec3* p3,
                          struct Vec3* p4, struct Vec3* p5, int* outT, int* outV, int* outW, int* outU) {
    struct Vec3 edge1, edge2, edge0;
    SubtractVec3(p3, p2, &edge1);
    SubtractVec3(p4, p2, &edge2);
    SubtractVec3(p0, p1, &edge0);

    struct FixedVec3 normal;
    CrossProductFixed020c2e34((int*)&edge1, (int*)&edge2, (int*)&normal);

    int denom = DotFixedVec3((struct FixedVec3*)&edge0, &normal);
    if (denom <= 0) {
        return 0;
    }

    struct Vec3 toP0;
    SubtractVec3(p0, p2, &toP0);

    int uDot = DotFixedVec3((struct FixedVec3*)&toP0, &normal);
    *outU = uDot;
    if (uDot < 0) {
        return 0;
    }
    if (uDot > denom) {
        return 0;
    }

    struct FixedVec3 normal2;
    CrossProductFixed020c2e34((int*)&edge0, (int*)&toP0, (int*)&normal2);

    int vDot = DotFixedVec3((struct FixedVec3*)&edge2, &normal2);
    *outV = vDot;
    if (vDot >= 0 && vDot <= denom) {
        /* continue */
    } else {
        return -1;
    }

    int negWDot = -DotFixedVec3((struct FixedVec3*)&edge1, &normal2);
    *outW = negWDot;
    if (negWDot >= 0 && *outV + negWDot <= denom) {
        /* continue */
    } else {
        return -1;
    }

    int invDenom = HwDivideRounded020c2bf4(0x1000, denom);

    *outU = (int)(((long long)*outU * invDenom + 0x800) >> 12);
    *outV = (int)(((long long)*outV * invDenom + 0x800) >> 12);
    *outW = (int)(((long long)*outW * invDenom + 0x800) >> 12);
    *outT = 0x1000 - *outV - *outW;
    return 1;
}
