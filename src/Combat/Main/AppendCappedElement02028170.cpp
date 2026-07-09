#include <globaldefs.h>

struct Elem02028170 {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned short h4;
    unsigned short h6;
    unsigned short h8;
    int w12;
};

struct Container02028170 {
    unsigned char capacity;
    char pad;
    unsigned char count;
    char pad2;
    struct Elem02028170* base;
};

// USA: func_02028170
ARM void AppendCappedElement02028170(struct Container02028170* c, struct Elem02028170* src) {
    unsigned char count = c->count;
    struct Elem02028170* dst;
    if (c->capacity <= count) return;
    dst = &c->base[count];
    dst->b0 = src->b0;
    dst->b1 = src->b1;
    dst->b2 = src->b2;
    dst->b3 = src->b3;
    dst->h4 = src->h4;
    dst->h6 = src->h6;
    dst->h8 = src->h8;
    dst->w12 = src->w12;
    c->count++;
}
