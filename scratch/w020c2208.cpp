#include <globaldefs.h>

struct Vec3Block_020c2208 { unsigned int v[3]; };
struct Vec4Block_020c2208 { Vec3Block_020c2208 xyz; unsigned int pad; };

// USA: func_020c2208
ARM void CopyVec3SkipWord_020c2208(Vec4Block_020c2208* src, Vec3Block_020c2208* dst) {
    *dst = src->xyz;
    dst++; src++;
    *dst = src->xyz;
    dst++; src++;
    *dst = src->xyz;
    dst++; src++;
    *dst = src->xyz;
}
