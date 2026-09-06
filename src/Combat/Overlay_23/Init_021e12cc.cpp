#include <globaldefs.h>

struct Struct_021e12cc {
    int a;
    int b;
    short c;
    unsigned short d;
    unsigned short e;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char rest : 6;
    unsigned char f;
};

// USA: func_ov023_021e12cc
ARM void Init_021e12cc(struct Struct_021e12cc* s) {
    s->a = 0;
    s->b = 0;
    s->c = -1;
    s->d = 0xffff;
    s->e = 0xffff;
    s->bit0 = 0;
    s->bit1 = 0;
    s->rest = 0;
    s->f = 0;
}
