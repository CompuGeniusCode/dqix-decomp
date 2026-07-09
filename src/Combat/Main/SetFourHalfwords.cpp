#include <globaldefs.h>

struct Struct0204408c {
    short x;
    short y;
    short z;
    short w;
};

// USA: func_0204408c
ARM void SetFourHalfwords(struct Struct0204408c* s, short x, short y, short z, short w) {
    s->x = x;
    s->y = y;
    s->z = z;
    s->w = w;
}
