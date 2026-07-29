#include <globaldefs.h>

struct Mtx43_020c199c { unsigned int v[12]; };

// USA: func_020c199c
THUMB void BuildRotYMatrix43_020c199c(struct Mtx43_020c199c* dst, int s, int c) {
    unsigned int* p = dst->v;
    p[6] = s;
    *p++ = c;
    *p++ = 0;
    *p++ = -s;
    *p++ = 0;
    *p++ = 0x1000;
    *p++ = 0;
    p++;
    *p++ = 0;
    *p++ = c;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
}
