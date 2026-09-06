#include <globaldefs.h>

struct Entry_020278a4 {
    int id;
    char unk[0x20];
};

struct List_020278a4 {
    char unk[0x20];
    struct Entry_020278a4* entries;
    int count;
};

// USA: func_020278a4
ARM int FindEntryIndexById(struct List_020278a4* list, int id) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (id == list->entries[i].id) {
            return i;
        }
    }
    return -1;
}
