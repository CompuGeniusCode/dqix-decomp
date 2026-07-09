#include <globaldefs.h>

struct S_cc68c {
    char pad0[0x54];
    int f54;
    int f58;
};

// USA: func_020cc68c
ARM void ZeroPairIfEitherZero(struct S_cc68c* p, int a, int b) {
    if (b == 0) {
        a = 0;
    } else if (a == 0) {
        b = 0;
    }
    p->f54 = a;
    p->f58 = b;
}
