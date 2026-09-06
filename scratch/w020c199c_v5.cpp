#include <globaldefs.h>

struct Mtx43_020c199c { unsigned int v[12]; };
struct Pair_020c199c { unsigned int a, b; };
struct Trip_020c199c { unsigned int a, b, c; };

// USA: func_020c199c
THUMB void BuildRotYMatrix43_020c199c(struct Mtx43_020c199c* dst, int s, int c) {
    dst->v[6] = s;
    struct Pair_020c199c p0 = { (unsigned int)c, 0 };
    *(struct Pair_020c199c*)&dst->v[0] = p0;
    struct Pair_020c199c p1 = { (unsigned int)-s, 0 };
    *(struct Pair_020c199c*)&dst->v[2] = p1;
    struct Pair_020c199c p2 = { 0x1000, 0 };
    *(struct Pair_020c199c*)&dst->v[4] = p2;
    struct Trip_020c199c t0 = { 0, (unsigned int)c, 0 };
    *(struct Trip_020c199c*)&dst->v[7] = t0;
    struct Pair_020c199c p3 = { 0, 0 };
    *(struct Pair_020c199c*)&dst->v[10] = p3;
}
