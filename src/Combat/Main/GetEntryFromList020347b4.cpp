#include <globaldefs.h>

struct Entry_020347b4 {
    char unk[0x24];
};

struct List_020347b4 {
    struct Entry_020347b4* entries;
    unsigned short count;
};

// USA: func_020347b4
ARM struct Entry_020347b4* GetEntryFromList020347b4(struct List_020347b4* list, int index) {
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
