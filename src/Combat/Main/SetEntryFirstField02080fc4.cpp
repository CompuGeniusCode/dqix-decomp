#include <globaldefs.h>

struct Entry02080fc4 { int value; };
struct List0207f6ac { struct Entry02080fc4* entries; short count; };
struct Entry02080fc4* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);

struct Container02080fc4 { char pad[4]; struct List0207f6ac list; };

// USA: func_02080fc4
ARM void SetEntryFirstField02080fc4(struct Container02080fc4* obj, int id, int value) {
    struct Entry02080fc4* e = FindEntryByShortId0207f6ac(&obj->list, id);
    if (e != NULL) {
        e->value = value;
    }
}
