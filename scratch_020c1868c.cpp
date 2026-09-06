#include <globaldefs.h>

struct Blk3_020c1868 { unsigned int v[3]; };
struct Vec4_020c1868 { unsigned int v[4]; };

// USA: func_020c1868
ARM void CopyVec3ToVec4Array020c1868(Blk3_020c1868* src, Vec4_020c1868* dst) {
    *(Blk3_020c1868*)dst = *src;
    dst->v[3] = 0;
    src++; dst++;
    *(Blk3_020c1868*)dst = *src;
    dst->v[3] = 0;
    src++; dst++;
    *(Blk3_020c1868*)dst = *src;
    dst->v[3] = 0;
    src++; dst++;
    *(Blk3_020c1868*)dst = *src;
    dst->v[3] = 0x1000;
}
