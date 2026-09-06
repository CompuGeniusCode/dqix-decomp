#include <globaldefs.h>

struct InitSubstruct0205c73cData {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fc;
    unsigned short f10;
    unsigned char f12;
    unsigned char f13;
    unsigned char f14;
    unsigned char f15;
    unsigned char f16;
};

// USA: func_0205c73c
ARM void InitSubstruct0205c73c(struct InitSubstruct0205c73cData* p) {
    p->f4 = 0;
    p->f0 = 0;
    p->fc = 0x8000;
    p->f8 = 0x8000;
    p->f10 = 0x7fff;
    p->f12 = 30;
    p->f13 = 0;
    p->f14 = 30;
    p->f15 = 0;
    p->f16 = 1;
}
