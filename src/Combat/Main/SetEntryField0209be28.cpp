#include <globaldefs.h>

struct EntryTable0209bd94;
struct Entry0209be28 {
    unsigned short key;
    unsigned short count;
    int field_4;
    unsigned char sub[0x18];
};
struct Entry0209be28* FindEntryByHalfword0209bd94(struct EntryTable0209bd94*, int);

// USA: func_0209be28
ARM void SetEntryField0209be28(struct EntryTable0209bd94* table, int key, int* value) {
    struct Entry0209be28* p = FindEntryByHalfword0209bd94(table, key);
    if (p != NULL) {
        p->field_4 = *value;
    }
}
