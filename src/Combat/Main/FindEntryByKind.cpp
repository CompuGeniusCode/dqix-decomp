#include <globaldefs.h>

struct FindEntryByKindEntry020d3d90 {
    unsigned char pad[0x10];
    unsigned char kind : 3;
    unsigned char : 5;
    unsigned char pad2[0x13];
};

struct FindEntryByKindContainer020d3d90 {
    struct FindEntryByKindEntry020d3d90 entries[5];
    int count;
};

// USA: func_020d3d90
ARM struct FindEntryByKindEntry020d3d90* FindEntryByKind(struct FindEntryByKindContainer020d3d90* c, int kind) {
    struct FindEntryByKindEntry020d3d90* e = c->entries;
    int i;
    for (i = 0; i < c->count; i++) {
        if (e->kind == kind) return e;
        e++;
    }
    return NULL;
}
