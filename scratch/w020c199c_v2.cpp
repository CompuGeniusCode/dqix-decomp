#include <globaldefs.h>

struct Mtx43_020c199c { unsigned int v[12]; };

// USA: func_020c199c
THUMB void BuildRotYMatrix43_020c199c(struct Mtx43_020c199c* dst, int s, int c) {
    dst->v[6] = s;
    dst->v[0] = c;
    dst->v[1] = 0;
    dst->v[2] = -s;
    dst->v[3] = 0;
    dst->v[4] = 0x1000;
    dst->v[5] = 0;
    dst->v[7] = 0;
    dst->v[8] = c;
    dst->v[9] = 0;
    dst->v[10] = 0;
    dst->v[11] = 0;
}
