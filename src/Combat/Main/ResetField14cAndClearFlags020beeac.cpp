#include <globaldefs.h>

struct Inner020beeac { int f0; };
struct Outer020beeac {
    char pad0[0x110];
    unsigned int f110;
    char pad1[0x38];
    struct Inner020beeac *f14c;
};

// USA: func_020beeac
ARM void ResetField14cAndClearFlags020beeac(struct Outer020beeac *p) {
    struct Inner020beeac *inner = p->f14c;
    if (inner != NULL) {
        inner->f0 = 0;
        p->f14c = NULL;
    }
    p->f110 &= ~0x1;
    p->f110 &= ~0x4;
    p->f110 &= ~0x2;
}
