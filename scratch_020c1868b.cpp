#include <globaldefs.h>

struct Vec3_020c1868 { unsigned int v[3]; };
struct Vec4_020c1868 { unsigned int v[4]; };

// USA: func_020c1868
ARM void CopyVec3ToVec4Array020c1868(Vec3_020c1868* src, Vec4_020c1868* dst) {
    dst->v[0] = src->v[0];
    dst->v[1] = src->v[1];
    dst->v[2] = src->v[2];
    dst->v[3] = 0;
    dst++; src++;
    dst->v[0] = src->v[0];
    dst->v[1] = src->v[1];
    dst->v[2] = src->v[2];
    dst->v[3] = 0;
    dst++; src++;
    dst->v[0] = src->v[0];
    dst->v[1] = src->v[1];
    dst->v[2] = src->v[2];
    dst->v[3] = 0;
    dst++; src++;
    dst->v[0] = src->v[0];
    dst->v[1] = src->v[1];
    dst->v[2] = src->v[2];
    dst->v[3] = 0x1000;
}
