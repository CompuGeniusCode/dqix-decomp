#include <globaldefs.h>

struct Elem0207f018 {
    unsigned int w0;
    unsigned int w4;
    short h8;
    short ha;
    short hc;
    short he;
    short h10;
    unsigned char b12;
    unsigned char b13;
    unsigned char b14;
    unsigned char b15;
};

struct Arr0207f018 {
    struct Elem0207f018* base;
    short count;
    short capacity;
};

// USA: func_0207f018
ARM void AppendCappedElement0207f018(struct Arr0207f018* arr, struct Elem0207f018* src) {
    short count;
    struct Elem0207f018* dst;
    if (src == NULL) {
        return;
    }
    count = arr->count;
    if (arr->capacity <= count) {
        return;
    }
    dst = &arr->base[count];
    dst->w0 = src->w0;
    dst->w4 = src->w4;
    dst->h8 = src->h8;
    dst->ha = src->ha;
    dst->hc = src->hc;
    dst->he = src->he;
    dst->h10 = src->h10;
    dst->b12 = src->b12;
    dst->b13 = src->b13;
    dst->b14 = src->b14;
    dst->b15 = src->b15;
    arr->count = arr->count + 1;
}
