#include <globaldefs.h>

struct Struct02032fb8 {
    unsigned short x;
    unsigned short y;
    unsigned short z;
    unsigned short w;
};

// USA: func_02032fb8
ARM void ClearFourHalfwords(struct Struct02032fb8* s) {
    s->x = 0;
    s->y = 0;
    s->z = 0;
    s->w = 0;
}
