#include <globaldefs.h>

struct Entry020a83fc {
    unsigned char pad[0x18];
    unsigned short id;   // 0x18
    unsigned char pad2[0x2c - 0x1a];
};

struct Container020a83fc {
    struct Entry020a83fc* entries;  // 0x0
    unsigned short field4;          // 0x4
    unsigned short count;           // 0x6
};

// USA: func_020a83fc
ARM struct Entry020a83fc* FindEntryById020a83fc(struct Container020a83fc* container, int id) {
    struct Entry020a83fc* entry = container->entries;
    int i;
    if (id == 0x16a9) id = 0x708;
    if (id == 0x119a) id = 0x708;
    for (i = 0; i < container->count; i++, entry++) {
        if (entry->id == id) return entry;
    }
    return NULL;
}
