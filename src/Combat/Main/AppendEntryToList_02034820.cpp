#include <globaldefs.h>

struct List_020347b4;
struct Entry_020347b4;
Entry_020347b4* GetEntryFromList020347b4(List_020347b4* list, int index);

struct ListItem_02034820 {
    unsigned short f0;
    unsigned short f2;
    short f4;
    int f8;
};

struct ItemList_02034820 {
    char pad[0x8];
    ListItem_02034820* entries;
    unsigned short capacity;
    unsigned short count;
};

// USA: func_02034820  (semantic: AppendEntryToList_02034820)
extern "C" ARM void func_02034820(struct ItemList_02034820* list, struct ListItem_02034820* src) {
    Entry_020347b4* entry;
    ListItem_02034820* dst;
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
    list->entries[list->count].f8 = *(int*)((char*)entry + 0x1c);
    *(int*)((char*)entry + 0x1c) = (int)&list->entries[list->count];
    list->count = list->count + 1;
}
