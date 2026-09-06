#include <globaldefs.h>

struct Block020a825c {
    unsigned int v[4];
};

struct Elem020a825c {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned int w4;
    struct Block020a825c block;
    unsigned short h18;
    unsigned short h1a;
    unsigned short h1c;
    unsigned short gap1e;
    unsigned int w20;
    unsigned int w24;
    unsigned int w28;
};

struct List020a825c {
    struct Elem020a825c* base;
    unsigned short cap;
    unsigned short count;
};

// USA: func_020a825c
ARM void AppendElement020a825c(struct List020a825c* list, struct Elem020a825c* src) {
    struct Elem020a825c* dst;
    unsigned short count;
    unsigned short cap;
    if (src == 0) {
        return;
    }
    count = list->count;
    cap = list->cap;
    if (cap <= count) {
        return;
    }
    dst = &list->base[count];
    dst->b0 = src->b0;
    dst->b1 = src->b1;
    dst->b2 = src->b2;
    dst->b3 = src->b3;
    dst->w4 = src->w4;
    dst->block = src->block;
    dst->h18 = src->h18;
    dst->h1a = src->h1a;
    dst->h1c = src->h1c;
    dst->w20 = src->w20;
    dst->w24 = src->w24;
    dst->w28 = src->w28;
    list->count++;
}
