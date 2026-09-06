#include <globaldefs.h>

struct Element0207f5d0 {
    int f00;
    short f04;
    short f06;
    short f08;
    short f0a;
    short f0c;
    short f0e;
    unsigned short f10;
    unsigned char f12;
    unsigned char f13;
    unsigned char f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    short f28;
    unsigned char f2a;
    unsigned char f2b;
    unsigned char f2c;
    unsigned char f2d;
};

struct List0207f5d0 {
    struct Element0207f5d0* entries;
    short count;
    short max;
};

// USA: func_0207f5d0
ARM void AppendElement0207f5d0(struct List0207f5d0* list, struct Element0207f5d0* src) {
    struct Element0207f5d0* base;
    struct Element0207f5d0* dst;
    short count;
    base = list->entries;
    if (base == NULL) {
        return;
    }
    count = list->count;
    if (list->max <= count) {
        return;
    }
    dst = &base[count];
    dst->f00 = src->f00;
    dst->f04 = src->f04;
    dst->f06 = src->f06;
    dst->f08 = src->f08;
    dst->f0a = src->f0a;
    dst->f0c = src->f0c;
    dst->f0e = src->f0e;
    dst->f10 = src->f10;
    dst->f12 = src->f12;
    dst->f13 = src->f13;
    dst->f14 = src->f14;
    dst->f18 = src->f18;
    dst->f1c = src->f1c;
    dst->f20 = src->f20;
    dst->f24 = src->f24;
    dst->f28 = src->f28;
    dst->f2a = src->f2a;
    dst->f2b = src->f2b;
    dst->f2c = src->f2c;
    dst->f2d = src->f2d;
    list->count++;
}
