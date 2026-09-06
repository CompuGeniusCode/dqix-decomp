#include <globaldefs.h>

struct StructDE1D4 {
    int a, b, c, d;
    unsigned int field10Low : 10;
    unsigned int field10Mid : 10;
    unsigned int field10High : 12;
    short e, f, g, h, i;
};

// USA: func_020de1d4
ARM void InitStruct020de1d4(struct StructDE1D4* p) {
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->f = 0;
    p->g = -1;
    p->h = 0;
    p->i = 0;
    p->field10Low = 999;
    p->field10Mid = 999;
}
