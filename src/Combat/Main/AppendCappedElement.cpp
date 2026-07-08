#include <globaldefs.h>

struct Elem128 {
    unsigned char b0;
    unsigned char b1;
    unsigned short h2;
};

struct Array128 {
    struct Elem128* base;
    unsigned short capacity;
    unsigned short count;
};

// USA: func_0207c128
ARM void AppendCappedElement(struct Array128* arr, struct Elem128* src) {
    unsigned short count = arr->count;
    struct Elem128* dst;
    if (count >= arr->capacity) {
        return;
    }
    arr->count = count + 1;
    dst = &arr->base[count];
    dst->b0 = src->b0;
    dst->b1 = src->b1;
    dst->h2 = src->h2;
}
