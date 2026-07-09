#include <globaldefs.h>

struct Elem0201f0f0 {
    unsigned short f0;
    unsigned char f2;
    unsigned char f3;
    int f4;
    int f8;
};

struct List0201f0f0 {
    struct Elem0201f0f0* base;
    int count;
    int capacity;
};

// USA: func_0201f0f0
ARM void AppendElementCapped0201f0f0(struct List0201f0f0* list, struct Elem0201f0f0* src) {
    int count = list->count;
    struct Elem0201f0f0* dst;
    if (list->capacity <= count) {
        return;
    }
    list->count = count + 1;
    dst = &list->base[count];
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->f3 = src->f3;
    dst->f4 = src->f4;
    dst->f8 = src->f8;
}
