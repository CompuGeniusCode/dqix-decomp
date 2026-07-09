#include <globaldefs.h>

struct Block9Words {
    unsigned int v[9];
};

struct Block3Words {
    unsigned int v[3];
};

struct CopySrc02033edc {
    struct Block9Words a;
    struct Block3Words b;
};

struct CopyDst02033edc {
    unsigned char pad0[0xe0];
    unsigned char flags;
    unsigned char pad1[3];
    struct Block9Words a;
    struct Block3Words b;
};

// USA: func_02033edc
ARM void CopyBlocksSetFlag0x40(struct CopyDst02033edc* dst, struct CopySrc02033edc* src) {
    dst->flags |= 0x40;
    dst->a = src->a;
    dst->b = src->b;
}
