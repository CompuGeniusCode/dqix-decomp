#include <globaldefs.h>

struct ListEntry_02028430 {
    unsigned char id;
    unsigned char unk[0xF];
};

struct List_02028430 {
    unsigned char unk0[2];
    unsigned char count;
    unsigned char unk3;
    struct ListEntry_02028430* entries;
};

// USA: func_02028430
ARM struct ListEntry_02028430* GetListEntryChecked(struct List_02028430* list, int index) {
    struct ListEntry_02028430* entries;
    if (index < 0 || list->count <= index) {
        return NULL;
    }
    entries = list->entries;
    if (entries != NULL) {
        return &entries[index];
    }
    return NULL;
}
