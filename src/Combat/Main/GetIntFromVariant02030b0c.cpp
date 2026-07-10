#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

// USA: func_02030b0c
ARM int GetIntFromVariant02030b0c(struct Variant02030b0c* p) {
    switch (p->tag) {
    case 1:
        return p->u.i;
    case 2:
        return (int)p->u.f;
    default:
        return 0;
    }
}
