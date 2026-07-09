#include <globaldefs.h>

struct Vec3block0202ed0c {
    unsigned int v[3];
};

struct Block12_0202ed0c {
    unsigned int v[12];
};

struct Src0202ed0c {
    struct Vec3block0202ed0c a;
    struct Vec3block0202ed0c b;
    struct Vec3block0202ed0c c;
    struct Block12_0202ed0c d;
};

struct Dst0202ed0c {
    char pad[4];
    struct Vec3block0202ed0c a;
    struct Vec3block0202ed0c b;
    struct Vec3block0202ed0c c;
    struct Block12_0202ed0c d;
};

// USA: func_0202ed0c
ARM void CopyGroupedBlocks0202ed0c(struct Dst0202ed0c* dst, struct Src0202ed0c* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
}
