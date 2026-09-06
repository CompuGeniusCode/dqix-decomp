#include <globaldefs.h>

struct Vec3Block020c1868 { unsigned int v[3]; };
struct Vec4Block020c1868 { unsigned int v[4]; };

// USA: func_020c1868
ARM void ProbeQuad2(Vec3Block020c1868* src, Vec4Block020c1868* dst) {
    Vec4Block020c1868 t;
    t.v[3] = 0;
    *(Vec3Block020c1868*)&t = src[0];
    dst[0] = t;
}
