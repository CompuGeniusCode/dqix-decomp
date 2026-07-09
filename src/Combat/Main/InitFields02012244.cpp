#include <globaldefs.h>

struct S02012244 {
    unsigned short unk0;
    unsigned short unk2;
    unsigned short f4;
    unsigned short f6;
    unsigned short f8;
    unsigned short fa;
    unsigned short fc;
    unsigned short fe;
    unsigned short f10;
    unsigned short f12;
    unsigned short f14;
    unsigned short unk16;
    unsigned int f18;
    unsigned char f1c;
};

// USA: func_02012244
ARM void InitFields02012244(struct S02012244* s) {
    s->f4 = 1;
    s->f6 = 2;
    s->f8 = 3;
    s->fa = 4;
    s->fc = 5;
    s->fe = 6;
    s->f10 = 7;
    s->f12 = 0;
    s->f14 = 1000;
    s->f1c = 1;
    s->f18 = 0;
}
