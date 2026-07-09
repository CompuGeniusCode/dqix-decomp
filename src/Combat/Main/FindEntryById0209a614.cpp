#include <globaldefs.h>

struct FindEntry0209a614 {
    unsigned short field0;
    unsigned short id;
    char pad[8];
};
struct FindList0209a614 {
    struct FindEntry0209a614* entries;
    int count;
};

// USA: func_0209a614
ARM struct FindEntry0209a614* FindEntryById0209a614(struct FindList0209a614* list, int id) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (id == list->entries[i].id) {
            return &list->entries[i];
        }
    }
    return NULL;
}
