#include <globaldefs.h>

struct Vec3_020c1868 { unsigned int v[3]; };
struct Vec4_020c1868 { unsigned int v[4]; };

// USA: func_020c1868
ARM void CopyVec3ToVec4Array020c1868(Vec3_020c1868* src, Vec4_020c1868* dst) {
    unsigned int a0 = src->v[0];
    unsigned int a1 = src->v[1];
    unsigned int a2 = src->v[2];
    dst->v[0] = a0;
    dst->v[1] = a1;
    dst->v[2] = a2;
    dst->v[3] = 0;
    src++; dst++;
    unsigned int b0 = src->v[0];
    unsigned int b1 = src->v[1];
    unsigned int b2 = src->v[2];
    dst->v[0] = b0;
    dst->v[1] = b1;
    dst->v[2] = b2;
    dst->v[3] = 0;
    src++; dst++;
    unsigned int c0 = src->v[0];
    unsigned int c1 = src->v[1];
    unsigned int c2 = src->v[2];
    dst->v[0] = c0;
    dst->v[1] = c1;
    dst->v[2] = c2;
    dst->v[3] = 0;
    src++; dst++;
    unsigned int d0 = src->v[0];
    unsigned int d1 = src->v[1];
    unsigned int d2 = src->v[2];
    dst->v[0] = d0;
    dst->v[1] = d1;
    dst->v[2] = d2;
    dst->v[3] = 0x1000;
}
