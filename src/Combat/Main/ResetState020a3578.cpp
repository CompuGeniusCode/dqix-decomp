#include <globaldefs.h>

struct ResetState020a3578Struct {
    short f0;
    short f2;
    signed char f4;
    signed char f5;
    short f6;
    short f8;
    short fa;
    int fc;
    char pad10[0x24 - 0x10];
    signed char f24;
    signed char f25;
    char pad26[0x2a - 0x26];
    signed char f2a;
    char pad2b;
    int f2c;
    int f30;
    signed char f34;
    signed char f35;
};

// USA: func_020a3578
ARM void ResetState020a3578(struct ResetState020a3578Struct* s) {
    s->f0 = 0;
    s->f6 = 0;
    s->f8 = 0;
    s->fa = 0;
    s->f2a = -1;
    s->f2c = 0;
    s->f30 = 0;
    s->f34 = 0;
    s->fc = -1;
    s->f4 = 0;
    s->f2 = 0x75a4;
    s->f24 = 0;
    s->f25 = 0;
    s->f35 = 0;
    s->f5 = 2;
}
