#include <globaldefs.h>

struct Inner020bec80 { char pad[0x14c]; int f14c; };
struct Outer020bec80 { struct Inner020bec80 *f0; };

// USA: func_020bec80
ARM void ClearInnerField14c020bec80(struct Outer020bec80 *p) {
    struct Inner020bec80 *inner = p->f0;
    if (inner != NULL) {
        inner->f14c = 0;
        p->f0 = NULL;
    }
}
