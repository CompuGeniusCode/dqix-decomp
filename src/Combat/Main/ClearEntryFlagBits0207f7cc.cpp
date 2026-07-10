#include <globaldefs.h>

struct List0207f6ac;

struct FlagEntry0207f7cc {
    char pad[0x2a];
    unsigned char flags;
};

extern struct FlagEntry0207f7cc* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);

// USA: func_0207f7cc
ARM void ClearEntryFlagBits0207f7cc(struct List0207f6ac* list, int id, int mask) {
    struct FlagEntry0207f7cc* e = FindEntryByShortId0207f6ac(list, id);
    if (e != NULL) {
        e->flags &= ~mask;
    }
}
