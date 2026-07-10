#include <globaldefs.h>

struct Pair020deb08;
short GetMaxOfHalfwords0And4(struct Pair020deb08* obj);

struct EntryList020deb24 {
    unsigned short a;
    unsigned short pad2;
    unsigned short b;
    unsigned short pad6;
    int pad8;
    void* entries;
};

// USA: func_020deb24
ARM void* GetEntryByIndex020deb24(struct EntryList020deb24* list, int index) {
    int count = GetMaxOfHalfwords0And4((struct Pair020deb08*)list);
    if (index < 0 || index >= count) {
        return NULL;
    }
    return (char*)list->entries + index * 0x20;
}
