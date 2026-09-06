#include <globaldefs.h>

struct Vec3_020406f8 {
    unsigned int v[3];
};

struct SrcA_020406f8 {
    char pad4[4];
    struct Vec3_020406f8 vec;
};

struct SrcB_020406f8 {
    char pad44[0x44];
    struct Vec3_020406f8 vec;
};

struct Node020406f8 {
    char pad[0x14];
    struct SrcA_020406f8* f14;
    struct SrcB_020406f8* f18;
    struct SrcB_020406f8* f1c;
};

// USA: func_020406f8
ARM void SelectVec3FromSources020406f8(struct Vec3_020406f8* dst, struct Node020406f8* n) {
    if (n->f14 != NULL) {
        *dst = n->f14->vec;
        return;
    }
    if (n->f18 != NULL) {
        *dst = n->f18->vec;
        return;
    }
    if (n->f1c != NULL) {
        *dst = n->f1c->vec;
        return;
    }
    {
        struct Vec3_020406f8 zero;
        zero.v[0] = 0;
        zero.v[1] = 0;
        zero.v[2] = 0;
        *dst = zero;
    }
}
