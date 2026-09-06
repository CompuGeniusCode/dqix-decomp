#include <globaldefs.h>

struct Quad020c1868 { unsigned int a, b, c, d; };

// USA: func_020c1868
ARM void ProbeQuad(unsigned int* src, Quad020c1868* dst) {
    Quad020c1868 t;
    t.a = src[0]; t.b = src[1]; t.c = src[2]; t.d = 0;
    *dst = t;
}
