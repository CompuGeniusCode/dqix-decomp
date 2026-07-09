#include <globaldefs.h>

struct Tween020c01ec { int f0; int f4; int f8; int fc; };

// USA: func_020c01ec
ARM void ResetTween020c01ec(struct Tween020c01ec *t) {
    t->f0 = t->f4 = 0;
    t->f8 = t->fc = 0;
}
