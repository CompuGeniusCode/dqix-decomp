#include <globaldefs.h>

struct RangeEntry020e587c {
    int field0;
    int field4;
    int lo;
    int hi;
    int field10;
};

struct RangeList020e587c {
    struct RangeEntry020e587c* base;
    int capacity;
    int count;
};

// USA: func_020e587c
ARM void AppendRangeEntry020e587c(struct RangeList020e587c* list, struct RangeEntry020e587c* entry) {
    struct RangeEntry020e587c* dst;
    if (entry == NULL) {
        return;
    }
    if (list->capacity <= list->count) {
        return;
    }
    dst = &list->base[list->count];
    dst->field0 = entry->field0;
    dst->field4 = entry->field4;
    dst->lo = entry->lo;
    dst->hi = entry->hi;
    dst->field10 = entry->field10;
    list->count++;
}
