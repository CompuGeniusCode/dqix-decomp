#include <globaldefs.h>

struct Name020d3cf0 { unsigned char c[16]; };

struct Entry020d3cf0 {
    struct Name020d3cf0 name;
    unsigned char b10;
    unsigned char b11;
    unsigned char b12;
    unsigned char b13;
    unsigned int w14;
    unsigned int w18;
    unsigned int w1c;
    unsigned short h20;
    unsigned short h22;
};

struct Container020d3cf0 {
    struct Entry020d3cf0 entries[5];
    int count;
};

// USA: func_020d3cf0
ARM void AppendNamedEntry020d3cf0(struct Container020d3cf0* c, struct Entry020d3cf0* src) {
    int idx = c->count;
    struct Entry020d3cf0* dst;
    if (idx >= 5) return;
    dst = &c->entries[idx];
    c->count = idx + 1;
    dst->name = src->name;
    dst->b10 = src->b10;
    dst->b11 = src->b11;
    dst->b12 = src->b12;
    dst->b13 = src->b13;
    dst->w14 = src->w14;
    dst->w18 = src->w18;
    dst->w1c = src->w1c;
    dst->h20 = src->h20;
    dst->h22 = src->h22;
}
