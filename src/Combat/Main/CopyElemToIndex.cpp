#include <globaldefs.h>

struct Inner02094d14 { unsigned int v[3]; };
struct Elem02094d14 {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    struct Inner02094d14 mid;
};
struct Container02094d14 { struct Elem02094d14* base; };

// USA: func_02094d14
ARM void CopyElemToIndex(struct Container02094d14* c, struct Elem02094d14* src, int idx) {
    struct Elem02094d14* dst = &c->base[idx];
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->mid = src->mid;
}
