#include <globaldefs.h>

struct Entry02045c00 {
    char unk0[0x16];
    unsigned char unk16_b0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char unk16_rest : 5;
    char unk17;
    int word18;
};

struct Container02045c00 {
    char unk0[0x9b8];
    struct Entry02045c00 entries[0x80];
    unsigned char active[0x80];
    char unk1838[0x123];
    unsigned char flags195b;
};

// USA: func_02045c00
ARM int FindMatchingEntryIndex(struct Container02045c00* c, int id) {
    int i;
    if (id == 0) {
        return -1;
    }
    for (i = 0; i < 0x80; i++) {
        struct Entry02045c00* e;
        if (c->active[i] == 0) continue;
        e = &c->entries[i];
        if (id != e->word18) continue;
        if (c->flags195b & 0x80) {
            if (e->bit2) return i;
        } else if (c->flags195b & 0x2) {
            if (e->bit1) return i;
        } else {
            return i;
        }
    }
    return -1;
}
