#include <globaldefs.h>

struct Obj021fb23c {
    char pad[0x3c];
    short a;
    short b;
    short c;
};

// USA: func_ov023_021fb23c
ARM void SetThreeFields_021fb23c(struct Obj021fb23c *obj, short a, short b, short c) {
    obj->a = a;
    obj->b = b;
    obj->c = c;
}
