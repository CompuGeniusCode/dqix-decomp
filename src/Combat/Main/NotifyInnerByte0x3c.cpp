#include <globaldefs.h>

int EnqueueEvent0x7(int, int, int);

struct Inner020bc1cc { char pad[0x3c]; unsigned char f3c; };
struct Outer020bc1cc { struct Inner020bc1cc* volatile f0; };

// USA: func_020bc1cc
ARM void NotifyInnerByte0x3c(struct Outer020bc1cc* p, int arg2, int arg3) {
    if (p->f0 != NULL) {
        EnqueueEvent0x7(p->f0->f3c, arg2, arg3);
    }
}
