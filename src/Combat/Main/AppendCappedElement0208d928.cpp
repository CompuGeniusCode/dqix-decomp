#include <globaldefs.h>

struct Elem0208d928 {
    short h0;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
};

struct List0208d928 {
    struct Elem0208d928* base;
    short count;
    short cap;
};

// USA: func_0208d928
ARM void AppendCappedElement0208d928(struct List0208d928 *l, struct Elem0208d928 *e) {
    struct Elem0208d928 *base = l->base;
    struct Elem0208d928 *dst;
    if (base == NULL) return;
    if (l->cap <= l->count) return;
    dst = &base[l->count];
    dst->h0 = e->h0;
    dst->w4 = e->w4;
    dst->w8 = e->w8;
    dst->wc = e->wc;
    dst->w10 = e->w10;
    dst->w14 = e->w14;
    l->count++;
}
