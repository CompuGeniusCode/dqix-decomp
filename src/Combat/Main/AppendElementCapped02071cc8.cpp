#include <globaldefs.h>

struct Elem02071cc8 {
    short f0;
    short f2;
    short f4;
    short f6;
    short f8;
    unsigned short fa;
    int fc;
    int f10;
    short f14;
    short f16;
    short f18;
    short f1a;
    int f1c;
};

struct List02071cc8 {
    char pad0[4];
    struct Elem02071cc8* entries;
    unsigned short capacity;
    unsigned short count;
};

// USA: func_02071cc8
ARM void AppendElementCapped02071cc8(struct List02071cc8* list, struct Elem02071cc8* src) {
    struct Elem02071cc8* dst;
    if (list->capacity <= list->count) {
        return;
    }
    dst = &list->entries[list->count];
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->f4 = src->f4;
    dst->f6 = src->f6;
    dst->f8 = src->f8;
    dst->fa = src->fa;
    dst->fc = src->fc;
    dst->f10 = src->f10;
    dst->f14 = src->f14;
    dst->f16 = src->f16;
    dst->f18 = src->f18;
    dst->f1a = src->f1a;
    dst->f1c = src->f1c;
    list->count++;
}
