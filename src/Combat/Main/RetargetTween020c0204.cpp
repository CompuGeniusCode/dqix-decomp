#include <globaldefs.h>

struct Tween020c0260 { int f0; int f4; int f8; int fc; };

int EvaluateTween020c022c(struct Tween020c0260* t);

// USA: func_020c0204
ARM void RetargetTween020c0204(struct Tween020c0260* t, int end, int duration) {
    t->f0 = EvaluateTween020c022c(t);
    t->f4 = end;
    t->fc = duration;
    t->f8 = 0;
}
