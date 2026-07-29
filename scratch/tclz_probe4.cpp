#include <globaldefs.h>

struct Vec3Block020c1868 { unsigned int v[3]; };
struct Vec4Block020c1868 { unsigned int v[4]; };

// USA: func_020c1868
ARM void ProbeQuad4(Vec3Block020c1868* src, Vec4Block020c1868* dst) {
    Vec4Block020c1868 t;
    t.v[0] = src[0].v[0];
    t.v[1] = src[0].v[1];
    t.v[2] = src[0].v[2];
    t.v[3] = 0;
    dst[0] = t;
}
