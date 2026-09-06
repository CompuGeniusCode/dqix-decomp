#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void InitStruct02059cc8(unsigned char* obj);

struct Entry020d6d18 {
    unsigned char body[0xd4];
    int field_d4;
};

struct Container020d6d18 {
    Entry020d6d18 entries[12];
    int field_a20;
    short field_a24;
    short field_a26;
    SafeAllocator allocator;
    unsigned char field_a3c;
    unsigned char field_a3d;
    float field_a40;
    float field_a44;
};

// USA: func_020d6d18
ARM void ConstructEntryManager020d6d18(Container020d6d18* c) {
    for (int i = 0; i < 12; i++) {
        InitStruct02059cc8((unsigned char*)&c->entries[i]);
        c->entries[i].field_d4 = 0;
    }
    c->allocator.ResetAllocatorPointer();
    c->field_a20 = 0;
    c->field_a24 = 0;
    c->field_a26 = 0;
    c->field_a3c = 0;
    c->field_a3d = 0;
    c->field_a40 = 1.0f;
    c->field_a44 = -0.2f;
}
