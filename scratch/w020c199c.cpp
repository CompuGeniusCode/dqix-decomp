#include <globaldefs.h>

struct Mtx43_020c199c { unsigned int v[12]; };

// USA: func_020c199c
THUMB void BuildRotYMatrix43_020c199c(struct Mtx43_020c199c* dst, int s, int c) {
    unsigned int* p = dst->v;
    p[6] = s;
    p[0] = c;
    p[1] = 0;
    p[2] = -s;
    p[3] = 0;
    p[4] = 0x1000;
    p[5] = 0;
    p[7] = 0;
    p[8] = c;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
}
