#include <globaldefs.h>

struct Entry020725d8 {
    signed short id;
    char unk[0x2a];
};

struct List020725d8 {
    struct Entry020725d8* entries;
    short count;
};

// USA: func_020725d8
ARM struct Entry020725d8* FindEntryById020725d8(struct List020725d8* list, int id) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (id == list->entries[i].id) {
            return &list->entries[i];
        }
    }
    return 0;
}
