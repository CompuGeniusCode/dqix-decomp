#include <globaldefs.h>

struct Tween020c0260 { int f0; int f4; int f8; int fc; };

// USA: func_020c022c
ARM int EvaluateTween020c022c(struct Tween020c0260* t) {
    if (t->f8 >= t->fc) {
        return t->f4;
    }
    return t->f0 + t->f8 * (t->f4 - t->f0) / t->fc;
}
