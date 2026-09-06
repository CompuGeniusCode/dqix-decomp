#include <globaldefs.h>

struct List0207f0ac;

struct StatusEntry02081198 {
    char pad[0x12];
    unsigned char flags;
};

struct StatusEntry02081198* FindEntryByShortId0207f0ac(struct List0207f0ac* list, int id);

struct StatusOwner02081198 {
    char pad[0xc];
};

// USA: func_02081198
ARM void SetEntryNibbleByShortId(struct StatusOwner02081198* owner, int id, int enable) {
    struct StatusEntry02081198* e = FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)owner + 0xc), id);
    if (e == NULL) {
        return;
    }
    if (enable) {
        e->flags = (e->flags & ~0xf0) | 0x10;
    } else {
        e->flags = e->flags & ~0xf0;
    }
}
