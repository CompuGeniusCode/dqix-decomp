#include <globaldefs.h>

struct Arr11_02098834 { char v[11]; };
struct Arr6_02098834 { char v[6]; };
struct Sh14_02098834 { short v[14]; };
struct In6_02098834 { int v[6]; };
struct In31_02098834 { int v[31]; };

struct S02098834 {
    struct Arr11_02098834 a;
    unsigned char b;
    int c;
    int d;
    struct Arr6_02098834 e;
    struct Sh14_02098834 f;
    struct In6_02098834 g;
    struct Sh14_02098834 h;
    struct In31_02098834 i;
};

// USA: func_02098834
ARM struct S02098834* CopyStruct02098834(struct S02098834* dst, struct S02098834* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    dst->g = src->g;
    dst->h = src->h;
    dst->i = src->i;
    return dst;
}
