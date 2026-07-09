#include <globaldefs.h>
#pragma optimize_for_size off

struct Entry020afd5c {
    unsigned int offset;
    unsigned int pad;
};

struct Table020afd5c {
    unsigned char pad0[8];
    unsigned short count;
    unsigned short pad2;
    struct Entry020afd5c entries[1];
};

struct Owner020afd5c {
    unsigned char pad[0x60];
    struct Table020afd5c *table;
    unsigned int base;
};

// USA: func_020afd5c
ARM unsigned int GetOffsetData020afd5c(struct Owner020afd5c *owner, unsigned int index) {
    struct Table020afd5c *table = owner->table;
    unsigned int result = 0;
    if (index < table->count) {
        result = owner->base + table->entries[index].offset;
    }
    return result;
}
