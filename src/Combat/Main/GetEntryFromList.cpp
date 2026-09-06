#include <globaldefs.h>

struct Entry_02027878 {
    char unk[0x24];
};

struct List_02027878 {
    char unk[0x20];
    struct Entry_02027878* entries;
    int count;
};

// USA: func_02027878
ARM struct Entry_02027878* GetEntryFromList(struct List_02027878* list, int index) {
    if (index < 0) {
        goto ret0;
    }
    if (list->count > index) {
        goto valid;
    }
ret0:
    return 0;
valid:
    return &list->entries[index];
}
