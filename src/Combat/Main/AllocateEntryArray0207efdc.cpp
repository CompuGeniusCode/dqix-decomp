#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct EntryArray0207efdc {
    void* entries;   // 0x0
    short idx;       // 0x4
    short count;     // 0x6
};

// USA: func_0207efdc
ARM void AllocateEntryArray0207efdc(struct EntryArray0207efdc* obj, SafeAllocator* alloc, int count) {
    if (alloc == NULL) return;
    if (count < 0) return;
    obj->idx = 0;
    obj->count = count;
    obj->entries = alloc->Allocate(count * 0x18);
}
