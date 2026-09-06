#include <globaldefs.h>

struct Entry0209bd94 {
    unsigned short key;
    unsigned char pad[0x1e];
};

struct EntryTable0209bd94 {
    struct Entry0209bd94 entries[6];
    int count;
};

// USA: func_0209bd94
ARM struct Entry0209bd94* FindEntryByHalfword0209bd94(struct EntryTable0209bd94* table, int key) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (key == table->entries[i].key) {
            return &table->entries[i];
        }
    }
    return NULL;
}
