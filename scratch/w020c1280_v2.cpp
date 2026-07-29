#include <globaldefs.h>

struct Mtx33_020c1280 { unsigned int v[9]; };

// USA: func_020c1280
THUMB void BuildRotYMatrix33_020c1280(struct Mtx33_020c1280* dst, int s, int c) {
    dst->v[0] = c;
    dst->v[8] = c;
    int zero = 0;
    dst->v[1] = zero;
    dst->v[3] = zero;
    dst->v[5] = zero;
    dst->v[7] = zero;
    int negS = -s;
    int oneShifted = 0x1000;
    dst->v[6] = s;
    dst->v[2] = negS;
    dst->v[4] = oneShifted;
}
