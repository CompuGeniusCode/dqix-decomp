#include <globaldefs.h>

struct Entry02080cc0 { char pad[0x13]; unsigned char flags; };
struct List0207f6ac { struct Entry02080cc0* entries; short count; };
struct Entry02080cc0* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);

struct Container02080cc0 { char pad[4]; struct List0207f6ac list; };

// USA: func_02080cc0
ARM void SetEntryHighNibble0x13(struct Container02080cc0* obj, int id, int value) {
    struct Entry02080cc0* e = FindEntryByShortId0207f6ac(&obj->list, id);
    if (e != NULL) {
        e->flags = (e->flags & ~0xf0) | ((value & 0xf) << 4);
    }
}
