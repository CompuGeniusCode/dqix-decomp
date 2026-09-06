#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void InitStruct02059cc8(unsigned char* obj);

struct Entry020d6f44 {
    unsigned char body[0xd4];
    int field_d4;
};

struct Container020d6f44 {
    Entry020d6f44 entries[12];
    unsigned char pad_a20[4];
    short field_a24;
    short field_a26;
    SafeAllocator allocator;
};

// USA: func_020d6f44
ARM void ResetEntryManager020d6f44(Container020d6f44* c) {
    c->allocator.Reset();
    for (int i = 0; i < 12; i++) {
        InitStruct02059cc8((unsigned char*)&c->entries[i]);
        c->entries[i].field_d4 = 0;
    }
    c->field_a24 = 0;
    c->field_a26 = 0;
}
