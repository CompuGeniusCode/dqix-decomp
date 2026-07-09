#include <globaldefs.h>

struct Entry0209a9dc { unsigned short id; unsigned short pad; };
struct Base0209a9dc {
    struct Entry0209a9dc entries[0x42];
    int count;
};
struct Holder0209a9dc {
    struct Base0209a9dc* base;
};

// USA: func_0209a9dc
ARM struct Entry0209a9dc* FindEntryById0209a9dc(struct Holder0209a9dc* h, int i) {
    int j;
    struct Base0209a9dc* base;
    base = h->base;
    if (base == NULL) return NULL;
    if (i >= 0x42) return NULL;
    if (base->entries[i].id == i) return &base->entries[i];
    for (j = 0; j < base->count; j++) {
        if (base->entries[j].id == i) return &base->entries[j];
    }
    return NULL;
}
