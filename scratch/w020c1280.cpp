#include <globaldefs.h>

struct Mtx33_020c1280 { unsigned int v[9]; };

// USA: func_020c1280
THUMB void BuildRotYMatrix33_020c1280(struct Mtx33_020c1280* dst, int s, int c) {
    dst->v[0] = c;
    dst->v[8] = c;
    dst->v[1] = 0;
    dst->v[3] = 0;
    dst->v[5] = 0;
    dst->v[7] = 0;
    int ns = -s;
    dst->v[6] = s;
    dst->v[2] = ns;
    dst->v[4] = 0x1000;
}
