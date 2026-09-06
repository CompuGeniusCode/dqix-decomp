#include <globaldefs.h>

struct Foo02042fcc {
    short a0;
    short a2;
    short a4;
    short a6;
    int a8;
    int ac;
    int a10;
    int a14;
    short a18;
};

// USA: func_02042fcc
ARM void ResetFoo02042fcc(struct Foo02042fcc* p) {
    p->a6 = 0;
    p->a4 = 0;
    p->a2 = 0;
    p->a0 = 0;
    p->a8 = 0;
    p->ac = 0;
    p->a14 = 0;
    p->a10 = 0;
    p->a18 = 0x7fff;
}
