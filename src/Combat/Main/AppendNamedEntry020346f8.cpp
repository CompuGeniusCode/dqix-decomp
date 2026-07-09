#include <globaldefs.h>

struct Name020346f8 {
    unsigned char c[16];
};

struct Entry020346f8 {
    struct Name020346f8 name;
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
    unsigned int w3;
    unsigned int w4;
};

struct List020346f8 {
    struct Entry020346f8* entries;
    unsigned short count;
    unsigned short capacity;
};

// USA: func_020346f8
ARM void AppendNamedEntry020346f8(struct List020346f8* list, struct Entry020346f8* src) {
    unsigned short count = list->count;
    struct Entry020346f8* e;
    if (list->capacity <= count) {
        return;
    }
    list->count = count + 1;
    e = &list->entries[count];
    e->name = src->name;
    e->w0 = src->w0;
    e->w1 = src->w1;
    e->w2 = src->w2;
    e->w3 = src->w3;
    e->w4 = src->w4;
}
