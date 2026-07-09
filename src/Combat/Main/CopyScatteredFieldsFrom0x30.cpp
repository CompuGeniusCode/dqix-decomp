#include <globaldefs.h>

struct S_cbb90 {
    char pad0[0x20];
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
};

// USA: func_020cbb90
ARM int CopyScatteredFieldsFrom0x30(struct S_cbb90* p) {
    p->f24 = p->f30;
    p->f2c = p->f30;
    p->f28 = p->f34;
    p->f20 = p->f38;
    return 0;
}
