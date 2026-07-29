#include <globaldefs.h>

struct Src3020c1868 { unsigned int a, b, c; };
struct Dst4020c1868 { unsigned int a, b, c, d; };

// USA: func_020c1868
ARM void ProbeQuad5(Src3020c1868* src, Dst4020c1868* dst) {
    dst[0].a = src[0].a;
    dst[0].b = src[0].b;
    dst[0].c = src[0].c;
    dst[0].d = 0;
}
