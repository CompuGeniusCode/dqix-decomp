#include <globaldefs.h>

struct Entry02087574 {
    unsigned char pad[0x10];
    signed char id;
    unsigned char pad2[3];
};

struct EntryTable02087574 {
    unsigned char pad[0xf2c];
    struct Entry02087574 entries[3];
};

// USA: func_02087574
ARM struct Entry02087574* FindEntryBySignedId02087574(struct EntryTable02087574* obj, int id) {
    int i;
    if (id >= 0) {
        for (i = 0; i < 3; i++) {
            if (id == obj->entries[i].id) {
                return &obj->entries[i];
            }
        }
    }
    return 0;
}
