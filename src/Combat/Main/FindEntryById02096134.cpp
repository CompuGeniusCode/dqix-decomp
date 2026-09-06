#include <globaldefs.h>

struct FindEntryById02096134Elem { unsigned int id : 9; unsigned int hi : 23; char pad[0xc]; };
struct FindEntryById02096134Table { unsigned char count; char pad[3]; struct FindEntryById02096134Elem elems[1]; };

// USA: func_02096134
ARM struct FindEntryById02096134Elem* FindEntryById02096134(struct FindEntryById02096134Table* t, int id) {
    int i;
    if (id > 0xcc || id < 0) return NULL;
    for (i = 0; i < t->count; i++) {
        if (t->elems[i].id == id) return &t->elems[i];
    }
    return NULL;
}
