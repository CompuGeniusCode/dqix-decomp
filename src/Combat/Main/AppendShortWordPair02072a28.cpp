#include <globaldefs.h>

struct Elem02072a28 {
    short a;
    int b;
};

struct List02072a28 {
    struct Elem02072a28* entries;
    short capacity;
    short count;
};

// USA: func_02072a28
ARM void AppendShortWordPair02072a28(struct List02072a28* list, struct Elem02072a28* src) {
    struct Elem02072a28* dst;
    if (list->capacity <= list->count) {
        return;
    }
    dst = &list->entries[list->count];
    dst->a = src->a;
    dst->b = src->b;
    list->count++;
}
