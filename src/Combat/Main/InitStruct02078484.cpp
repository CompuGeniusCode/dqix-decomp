#include <globaldefs.h>

struct InitStruct02078484Struct {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    short f12;
    short f14;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20; int f24; int f28; int f2c; int f30;
    int f34; int f38; int f3c; int f40;
    int f44; int f48; int f4c;
};

// USA: func_02078484
ARM void InitStruct02078484(struct InitStruct02078484Struct* p) {
    p->f00 = 0;
    p->f10 = 1;
    p->f12 = 0;
    p->f14 = -1;
    p->f16 = -1;
    p->f18 = -1;
    p->f1a = -1;
    p->f1c = -0x1000;
    p->f20 = 0;
    p->f24 = 0;
    p->f28 = 0;
    p->f2c = 0;
    p->f30 = 0;
    p->f34 = 0;
    p->f38 = 0;
    p->f3c = 0;
    p->f40 = 0;
    p->f44 = 0x1000;
    p->f48 = 0x1000;
    p->f4c = 0x1000;
    p->b0 = 0;
    p->b1 = 0;
    p->b2 = 1;
    p->b3 = 0;
    p->b4 = 0;
    p->b5 = 0;
    p->b6 = 0;
    p->b7 = 0;
}
