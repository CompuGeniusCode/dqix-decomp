#include <globaldefs.h>

struct Vec3_020c2208 { unsigned int v[3]; };

// USA: func_020c2208
ARM void CopyVec4XyzToVec3Array020c2208(unsigned int* src, Vec3_020c2208* dst) {
    *dst = *(Vec3_020c2208*)src;
    dst++;
    src += 4;
    *dst = *(Vec3_020c2208*)src;
    dst++;
    src += 4;
    *dst = *(Vec3_020c2208*)src;
    dst++;
    src += 4;
    *dst = *(Vec3_020c2208*)src;
}
