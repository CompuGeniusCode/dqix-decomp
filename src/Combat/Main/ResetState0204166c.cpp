#include <globaldefs.h>

struct State0204166c {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    unsigned short f14;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char pad16 : 4;
    unsigned char f17;
    int f18;
};

// USA: func_0204166c
ARM void ResetState0204166c(struct State0204166c* s) {
    s->f0 = 0;
    s->f4 = 0;
    s->f8 = -1;
    s->fc = 0;
    s->f10 = 0;
    s->f14 = 0;
    s->f18 = 0;
    s->flag0 = 0;
    s->flag1 = 0;
    s->flag2 = 0;
    s->flag3 = 0;
    s->f17 = 0;
}
