#include <globaldefs.h>

struct Vec3_020c1868 { unsigned int v[3]; };
struct Vec4_020c1868 { unsigned int v[4]; };
union Overlay_020c1868 { Vec3_020c1868 asVec3; Vec4_020c1868 asVec4; };

// USA: func_020c1868
ARM void CopyVec3ToVec4Array020c1868(Vec3_020c1868* src, Overlay_020c1868* dst) {
    dst->asVec3 = *src;
    dst->asVec4.v[3] = 0;
    src++; dst++;
    dst->asVec3 = *src;
    dst->asVec4.v[3] = 0;
    src++; dst++;
    dst->asVec3 = *src;
    dst->asVec4.v[3] = 0;
    src++; dst++;
    dst->asVec3 = *src;
    dst->asVec4.v[3] = 0x1000;
}
