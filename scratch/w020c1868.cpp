#include <globaldefs.h>

struct Blk3_020c1868 { unsigned int v[3]; };
struct Blk4_020c1868 { unsigned int v[4]; };

// USA: func_020c1868
ARM void CopyVec3ArrayToVec4ArrayWithTrailingWord(Blk3_020c1868* src, Blk4_020c1868* dst) {
    unsigned int zero = 0;
    *(Blk3_020c1868*)dst = *src++;
    dst->v[3] = zero;
    dst++;
    *(Blk3_020c1868*)dst = *src++;
    dst->v[3] = zero;
    dst++;
    *(Blk3_020c1868*)dst = *src++;
    dst->v[3] = zero;
    dst++;
    *(Blk3_020c1868*)dst = *src++;
    dst->v[3] = 0x1000;
}
