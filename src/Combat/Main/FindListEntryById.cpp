#include <globaldefs.h>

struct ListEntry_020283c0 {
    unsigned char id;
    unsigned char unk[0xF];
};

struct List_020283c0 {
    unsigned char unk0[2];
    unsigned char count;
    unsigned char unk3;
    struct ListEntry_020283c0* entries;
};

// USA: func_020283c0
ARM struct ListEntry_020283c0* FindListEntryById(struct List_020283c0* list, int id) {
    int i;
    for (i = 0; i < list->count; i++) {
        struct ListEntry_020283c0* entries = list->entries;
        if (id == entries[i].id) {
            return &entries[i];
        }
    }
    return NULL;
}
