#include <globaldefs.h>

struct Blk4_020a2928 { unsigned int v[4]; };
struct Blk3_020a2928 { unsigned int v[3]; };

struct Struct020a2928 {
    struct Blk4_020a2928 a;
    unsigned int b;
    struct Blk3_020a2928 c;
    struct Blk3_020a2928 d;
};

// USA: func_020a2928
ARM struct Struct020a2928* CopyStruct020a2928(struct Struct020a2928* dst, struct Struct020a2928* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    return dst;
}
