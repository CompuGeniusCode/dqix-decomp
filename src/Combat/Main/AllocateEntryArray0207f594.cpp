#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct EntryArray0207f594 {
    void* entries;   // 0x0
    short idx;       // 0x4
    short count;     // 0x6
};

// USA: func_0207f594
ARM void AllocateEntryArray0207f594(struct EntryArray0207f594* obj, SafeAllocator* alloc, int count) {
    if (alloc == NULL) return;
    if (count <= 0) return;
    obj->idx = 0;
    obj->count = count;
    obj->entries = alloc->Allocate(count * 0x30);
}
