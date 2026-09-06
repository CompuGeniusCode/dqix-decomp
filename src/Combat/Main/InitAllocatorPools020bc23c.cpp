#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct AllocEntry020bc23c {
    char pad1[0x2c];
    unsigned char field2c;
    char pad2[0xf];
    unsigned char field3c;
    char pad3[7];
};

struct AllocPoolEntry020bc23c {
    SignedAllocatorList listA;
    SignedAllocatorList listB;
    int field18;
    int field1c;
    unsigned char field20;
};

extern SignedAllocatorList data_0210f3d8;
extern SignedAllocatorList data_0210f3cc;
extern AllocEntry020bc23c data_0210f3e4[16];
extern AllocPoolEntry020bc23c data_0210f824[32];

// USA: func_020bc23c
ARM void InitAllocatorPools020bc23c(void) {
    data_0210f3d8.Initialize(0x14);
    data_0210f3cc.Initialize(0x14);

    {
        int i = 0;
        AllocEntry020bc23c *entry = data_0210f3e4;
        do {
            entry->field2c = 0;
            entry->field3c = i;
            data_0210f3cc.InsertAtEnd((SignedAllocatorHeader*)entry);
            entry++;
            i++;
        } while (i < 0x10);
    }

    {
        AllocPoolEntry020bc23c *pool = data_0210f824;
        int i = 0;
        do {
            pool->listA.Initialize(0xc);
            pool->listB.Initialize(0);
            pool->field20 = 0x7f;
            pool->field18 = 1;
            pool->field1c = 0;
            pool++;
            i++;
        } while (i < 0x20);
    }
}
