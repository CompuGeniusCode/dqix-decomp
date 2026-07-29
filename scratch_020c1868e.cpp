#include <globaldefs.h>

struct Vec3_020c1868 { unsigned int v[3]; };
struct Vec4_020c1868 { unsigned int v[4]; };

// USA: func_020c1868
ARM void CopyVec3ToVec4Array020c1868(Vec3_020c1868* src, Vec4_020c1868* dst) {
    Vec3_020c1868 a = *src;
    dst->v[0] = a.v[0];
    dst->v[1] = a.v[1];
    dst->v[2] = a.v[2];
    dst->v[3] = 0;
    src++; dst++;
    Vec3_020c1868 b = *src;
    dst->v[0] = b.v[0];
    dst->v[1] = b.v[1];
    dst->v[2] = b.v[2];
    dst->v[3] = 0;
    src++; dst++;
    Vec3_020c1868 c = *src;
    dst->v[0] = c.v[0];
    dst->v[1] = c.v[1];
    dst->v[2] = c.v[2];
    dst->v[3] = 0;
    src++; dst++;
    Vec3_020c1868 d = *src;
    dst->v[0] = d.v[0];
    dst->v[1] = d.v[1];
    dst->v[2] = d.v[2];
    dst->v[3] = 0x1000;
}
