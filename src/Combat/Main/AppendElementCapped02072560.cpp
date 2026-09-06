#include <globaldefs.h>

struct Mid02072560 {
    unsigned short v[18];
};

struct Elem02072560 {
    short f0;
    short f2;
    struct Mid02072560 mid;
    unsigned short f28;
    unsigned char f2a;
    unsigned char f2b;
};

struct List02072560 {
    struct Elem02072560* entries;
    short capacity;
    short count;
};

// USA: func_02072560
ARM void AppendElementCapped02072560(struct List02072560* list, struct Elem02072560* src) {
    struct Elem02072560* dst;
    if (list->capacity <= list->count) {
        return;
    }
    dst = &list->entries[list->count];
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->mid = src->mid;
    dst->f28 = src->f28;
    dst->f2a = src->f2a;
    dst->f2b = src->f2b;
    list->count++;
}
