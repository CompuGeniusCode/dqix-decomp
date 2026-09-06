#include <globaldefs.h>

struct Entry0xc6fc {
    char unk0[0x24];
    unsigned char count;
    char unk25[3];
};

struct RefArray0xc6fc {
    int unk0;
    struct Entry0xc6fc entries[32];
    char pad[0xE];
    unsigned short total;
};

// USA: func_0203c6fc
ARM void DecrementEntryCount0x24(struct RefArray0xc6fc* obj, short index) {
    struct Entry0xc6fc* entry;
    int count;
    if (index < 0) {
        return;
    }
    entry = &obj->entries[index];
    count = entry->count;
    if (count == 0) {
        return;
    }
    entry->count = count - 1;
    if (((count - 1) & 0xff) == 0) {
        obj->total--;
    }
}
