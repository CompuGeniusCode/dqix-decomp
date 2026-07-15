#include <globaldefs.h>

struct Entry_02153884 { int key; int val; };
struct Table_02153884 { struct Entry_02153884* pairs; int count; };

// USA: func_ov001_02153884
ARM void* FindTableEntry_02153884(struct Table_02153884* t, int key) {
    for (int i = 0; i < t->count; i++) {
        if (t->pairs[i].key == key) {
            struct Entry_02153884* e = &t->pairs[i];
            if (e->val == 0) return NULL;
            return e;
        }
    }
    return NULL;
}
