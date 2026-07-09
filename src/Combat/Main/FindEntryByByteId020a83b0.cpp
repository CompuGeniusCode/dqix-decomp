#include <globaldefs.h>

struct Entry020a83b0 {
    unsigned char field0;
    unsigned char id;
    unsigned char pad[0x2a];
};

struct List020a83b0 {
    struct Entry020a83b0 *entries;
    unsigned short capacity;
    unsigned short count;
};

// USA: func_020a83b0
ARM struct Entry020a83b0* FindEntryByByteId020a83b0(struct List020a83b0 *list, int id) {
    int i;
    if (id < 0) {
        return 0;
    }
    for (i = 0; i < list->count; i++) {
        struct Entry020a83b0 *entry = &list->entries[i];
        if (id == entry->id) {
            return entry;
        }
    }
    return 0;
}
