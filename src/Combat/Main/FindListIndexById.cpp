#include <globaldefs.h>

struct ListEntry_020283fc {
    unsigned char id;
    unsigned char unk[0xF];
};

struct List_020283fc {
    unsigned char unk0[2];
    unsigned char count;
    unsigned char unk3;
    struct ListEntry_020283fc* entries;
};

// USA: func_020283fc
ARM int FindListIndexById(struct List_020283fc* list, int id) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (id == list->entries[i].id) {
            return i;
        }
    }
    return -1;
}
