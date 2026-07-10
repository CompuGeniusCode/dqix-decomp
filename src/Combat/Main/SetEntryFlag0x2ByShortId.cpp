#include <globaldefs.h>

struct List0207f0ac;

struct StatusEntry02081164 {
    char pad[0x15];
    unsigned char flags;
};

struct StatusEntry02081164* FindEntryByShortId0207f0ac(struct List0207f0ac* list, int id);

struct StatusOwner02081164 {
    char pad[0xc];
};

// USA: func_02081164
ARM void SetEntryFlag0x2ByShortId(struct StatusOwner02081164* owner, int id, int enable) {
    struct StatusEntry02081164* e = FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)owner + 0xc), id);
    if (e == NULL) {
        return;
    }
    if (enable) {
        e->flags |= 0x2;
    } else {
        e->flags &= ~0x2;
    }
}
