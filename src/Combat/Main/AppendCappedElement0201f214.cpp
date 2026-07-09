#include <globaldefs.h>

struct Inner3_0201f214 { unsigned int v[3]; };

struct Element0201f214 {
    short s0;
    short s2;
    short s4;
    unsigned short h6;
    struct Inner3_0201f214 mid8;
    unsigned short h14;
    unsigned short h16;
    unsigned short h18;
    unsigned short h1a;
    unsigned short h1c;
    unsigned short h1e;
};

struct List0201f214 {
    char pad[0xc];
    struct Element0201f214* base;
    int count;
    int capacity;
};

// USA: func_0201f214
ARM void AppendCappedElement0201f214(struct List0201f214* list, struct Element0201f214* src) {
    int count = list->count;
    struct Element0201f214* dst;
    if (list->capacity <= count) {
        return;
    }
    list->count = count + 1;
    dst = &list->base[count];
    dst->s0 = src->s0;
    dst->s2 = src->s2;
    dst->s4 = src->s4;
    dst->h6 = src->h6;
    dst->mid8 = src->mid8;
    dst->h14 = src->h14;
    dst->h16 = src->h16;
    dst->h18 = src->h18;
    dst->h1a = src->h1a;
    dst->h1c = src->h1c;
    dst->h1e = src->h1e;
}
