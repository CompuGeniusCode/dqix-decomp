#include <globaldefs.h>

struct Entry_021d999c {
    short a;
    short b;
    int c;
    int d;
};

struct EntryListStruct_021d999c {
    char pad0[4];
    Entry_021d999c* items;
    unsigned short count;
    unsigned short capacity;
};

// USA: func_ov028_021d999c
ARM void AppendEntry_021d999c(EntryListStruct_021d999c* obj, Entry_021d999c* item) {
    if (obj->capacity <= obj->count) {
        return;
    }
    if (item == NULL) {
        return;
    }
    Entry_021d999c* dst = &obj->items[obj->count];
    dst->a = item->a;
    dst->b = item->b;
    dst->c = item->c;
    dst->d = item->d;
    obj->count = obj->count + 1;
}
