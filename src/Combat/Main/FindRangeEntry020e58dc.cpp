#include <globaldefs.h>

struct RangeEntry020e58dc {
    int field0;
    int field4;
    int lo;
    int hi;
    int field10;
};

struct RangeList020e58dc {
    struct RangeEntry020e58dc* base;
    int field4;
    int count;
};

// USA: func_020e58dc
ARM struct RangeEntry020e58dc* FindRangeEntry020e58dc(struct RangeList020e58dc* list, int key) {
    struct RangeEntry020e58dc* entry = list->base;
    int i;
    for (i = 0; i < list->count; i++) {
        if (entry->lo <= key && key < entry->hi) {
            return entry;
        }
        entry++;
    }
    return NULL;
}
