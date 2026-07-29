#include <globaldefs.h>

struct Pair020c1180 { unsigned int a, b; };
struct Mtx33_020c1180 {
    struct Pair020c1180 p[4];
    unsigned int last;
};

// USA: func_020c1180
ARM void SetIdentity33_020c1180(struct Mtx33_020c1180* dst) {
    struct Pair020c1180 one, zero;
    one.a = 0x1000; one.b = 0;
    dst->last = one.a;
    zero.a = 0; zero.b = 0;
    dst->p[0] = one;
    zero.a = 0;
    dst->p[1] = zero;
    dst->p[2] = one;
    dst->p[3] = zero;
}
