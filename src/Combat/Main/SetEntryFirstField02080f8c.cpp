#include <globaldefs.h>

struct Entry02080f8c { int value; };
struct List0207f6ac { struct Entry02080f8c* entries; short count; };
struct Entry02080f8c* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);

struct Container02080f8c { char pad[4]; struct List0207f6ac list; };

// USA: func_02080f8c
ARM void SetEntryFirstField02080f8c(struct Container02080f8c* obj, int id, int value) {
    struct Entry02080f8c* e = FindEntryByShortId0207f6ac(&obj->list, id);
    if (e != NULL) {
        e->value = value;
    }
}
