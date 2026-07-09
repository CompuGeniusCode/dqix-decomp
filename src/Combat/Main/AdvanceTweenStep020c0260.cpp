#include <globaldefs.h>

struct Tween020c0260 { int f0; int f4; int f8; int fc; };

// USA: func_020c0260
ARM void AdvanceTweenStep020c0260(struct Tween020c0260 *t) {
    if (t->f8 < t->fc) {
        t->f8 = t->f8 + 1;
    }
}
