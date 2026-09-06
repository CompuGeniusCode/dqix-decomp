#include <globaldefs.h>

struct Entry02027910 {
    int f0;
    int f1;
    int f2;
    int f3;
};

struct List02027910 {
    char pad[0x2c];
    Entry02027910* entries;
    int count;
};

struct List_020278a4;
int FindEntryIndexById(List_020278a4* list, int id);

// USA: func_02027910  (semantic: AppendEntry02027910)
extern "C" ARM void func_02027910(List02027910* list, int f0, int id, int f2, int f3) {
    list->entries[list->count].f0 = f0;
    list->entries[list->count].f1 = FindEntryIndexById((List_020278a4*)list, id);
    list->entries[list->count].f2 = f2;
    list->entries[list->count].f3 = f3;
    list->count++;
}
