#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Layout02189284 {
    char pad[0x1f4];
    void* f1f4;
    void* f1f8;
    void* f1fc;
    SafeAllocator allocs[6];
};

// USA: func_ov008_02189284
ARM void SetupAllocators_02189284(Layout02189284* obj, SafeAllocator* alloc) {
    obj->allocs[0].CreateTypeA(alloc->Allocate(0xa000), 0xa000);
    obj->allocs[1].CreateTypeA(alloc->Allocate(0xc00), 0xc00);
    obj->allocs[2].CreateTypeA(alloc->Allocate(0x5c00), 0x5c00);
    obj->allocs[3].CreateTypeA(alloc->Allocate(0x800), 0x800);
    obj->allocs[4].CreateTypeA(alloc->Allocate(0x2400), 0x2400);
    obj->allocs[5].CreateTypeA(alloc->Allocate(0x5400), 0x5400);
    obj->f1f8 = alloc->Allocate(0x140);
    obj->f1f4 = alloc->Allocate(0x54);
    obj->f1fc = alloc->Allocate(0x8);
}
