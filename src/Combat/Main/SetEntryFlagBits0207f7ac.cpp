#include <globaldefs.h>

struct List0207f6ac;

struct FlagEntry0207f7ac {
    char pad[0x2a];
    unsigned char flags;
};

extern struct FlagEntry0207f7ac* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);

// USA: func_0207f7ac
ARM void SetEntryFlagBits0207f7ac(struct List0207f6ac* list, int id, int mask) {
    struct FlagEntry0207f7ac* e = FindEntryByShortId0207f6ac(list, id);
    if (e != NULL) {
        e->flags |= mask;
    }
}
