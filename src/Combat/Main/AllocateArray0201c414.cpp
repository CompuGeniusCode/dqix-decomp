#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0201c414 {
    void* ptr;            // 0x0
    int count;            // 0x4
    int idx;              // 0x8
    char pad[0x14];       // 0xc..0x1f
    SafeAllocator* alloc; // 0x20
};

// USA: func_0201c414
ARM void AllocateArray0201c414(struct Foo0201c414* obj, int count) {
    obj->ptr = obj->alloc->Allocate(count << 5);
    if (obj->ptr != NULL) {
        obj->count = count;
        obj->idx = 0;
    }
}
