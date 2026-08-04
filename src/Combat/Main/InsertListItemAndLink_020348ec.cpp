#include <globaldefs.h>

struct List_020347b4;
struct Entry_020347b4;
Entry_020347b4* GetEntryFromList020347b4(List_020347b4* list, int index);

struct ListItem_020348ec {
    unsigned short f0;
    unsigned short f2;
    short f4;
    int f8;
};

struct ItemList_020348ec {
    char pad[0x10];
    ListItem_020348ec* entries;
    unsigned short count;
    unsigned short capacity;
};

// USA: func_020348ec  (semantic: InsertListItemAndLink_020348ec)
extern "C" ARM void func_020348ec(struct ItemList_020348ec* list, struct ListItem_020348ec* src) {
    Entry_020347b4* entry;
    ListItem_020348ec* dst;
    if (list->capacity <= list->count) {
        return;
    }
    entry = GetEntryFromList020347b4((List_020347b4*)list, src->f2);
    if (entry == 0) {
        return;
    }
    dst = &list->entries[list->count];
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->f4 = src->f4;
    dst->f8 = src->f8;
    list->entries[list->count].f8 = *(int*)((char*)entry + 0x20);
    *(int*)((char*)entry + 0x20) = (int)&list->entries[list->count];
    list->count = list->count + 1;
}
