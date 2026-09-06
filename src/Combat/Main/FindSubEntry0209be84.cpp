#include <globaldefs.h>

struct EntryTable0209bd94;
struct SubEntry0209be84 {
    unsigned short id : 12;
    unsigned short hi : 4;
    short b;
};
struct Entry0209be84 {
    unsigned short key;
    unsigned short count;
    int field_4;
    struct SubEntry0209be84 sub[6];
};
struct Entry0209be84* FindEntryByHalfword0209bd94(struct EntryTable0209bd94*, int);

#pragma optimize_for_size off

// USA: func_0209be84
ARM struct SubEntry0209be84* FindSubEntry0209be84(struct EntryTable0209bd94* table, unsigned int subKey, int key) {
    struct Entry0209be84* p = FindEntryByHalfword0209bd94(table, key);
    int i;
    if (p != NULL) {
        for (i = 0; i < p->count; i++) {
            if (p->sub[i].id == subKey) {
                return &p->sub[i];
            }
        }
    }
    return NULL;
}
