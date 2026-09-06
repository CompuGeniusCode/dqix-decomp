#include <globaldefs.h>

struct Vec3Block020c1868 { unsigned int v[3]; };
struct Vec4Block020c1868 { Vec3Block020c1868 xyz; unsigned int w; };

// USA: func_020c1868
ARM void ProbeQuad3(Vec3Block020c1868* src, Vec4Block020c1868* dst) {
    dst[0].w = 0;
    dst[0].xyz = src[0];
}
