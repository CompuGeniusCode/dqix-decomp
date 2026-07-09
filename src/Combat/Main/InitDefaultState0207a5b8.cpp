#include <globaldefs.h>

struct Struct0207a5b8 {
    int f0;
    int f4;
    int f8;
    int fc;
    unsigned char f10;
    unsigned char f11;
    unsigned char f12;
    unsigned char f13;
    unsigned char a : 2;
    unsigned char b : 1;
    unsigned char c : 4;
    unsigned char d : 1;
};

// USA: func_0207a5b8
ARM void InitDefaultState0207a5b8(struct Struct0207a5b8* s) {
    s->f0 = 0;
    s->f4 = -1;
    s->f10 = 2;
    s->f8 = 0;
    s->fc = 0;
    s->f11 = 0;
    s->f13 = 0x1f;
    s->f12 = 0;
    s->a = 0;
    s->b = 0;
    s->c = 0;
    s->d = 1;
}
