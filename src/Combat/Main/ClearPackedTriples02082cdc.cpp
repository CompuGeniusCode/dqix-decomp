#include <globaldefs.h>

struct PackedTriple02082cdc {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Obj02082cdc {
    struct PackedTriple02082cdc w[3];
};

// USA: func_02082cdc
ARM void ClearPackedTriples02082cdc(struct Obj02082cdc* p) {
    p->w[0].a = 0; p->w[0].b = 0; p->w[0].c = 0;
    p->w[1].a = 0; p->w[1].b = 0; p->w[1].c = 0;
    p->w[2].a = 0; p->w[2].b = 0; p->w[2].c = 0;
}
