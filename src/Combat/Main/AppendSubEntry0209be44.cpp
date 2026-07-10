#include <globaldefs.h>

struct EntryTable0209bd94;
struct SubEntry0209be44 { unsigned short a; short b; };
struct Entry0209be44 {
    unsigned short key;
    unsigned short count;
    int field_4;
    struct SubEntry0209be44 sub[6];
};
struct Entry0209be44* FindEntryByHalfword0209bd94(struct EntryTable0209bd94*, int);

// USA: func_0209be44
ARM void AppendSubEntry0209be44(struct EntryTable0209bd94* table, int key, struct SubEntry0209be44* src) {
    struct Entry0209be44* p = FindEntryByHalfword0209bd94(table, key);
    struct SubEntry0209be44* arr;
    struct SubEntry0209be44* e;
    int i;
    if (p == NULL) return;
    i = p->count;
    arr = p->sub;
    p->count = i + 1;
    e = &arr[i];
    e->a = src->a;
    e->b = src->b;
}
