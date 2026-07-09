#include <globaldefs.h>

struct Elem02071d60 {
    short key;
    char pad[0x1e];
};

struct List02071d60 {
    void* field0;
    struct Elem02071d60* data;
    unsigned short field8;
    unsigned short count;
};

// USA: func_02071d60
ARM struct Elem02071d60* FindEntryByKey02071d60(struct List02071d60* list, int key) {
    unsigned short i;
    for (i = 0; i < list->count; i++) {
        if (key == list->data[i].key) {
            return &list->data[i];
        }
    }
    return NULL;
}
