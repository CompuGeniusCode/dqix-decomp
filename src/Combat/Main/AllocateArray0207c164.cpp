#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0207c164 {
    void* ptr;             // 0x0
    unsigned short count;  // 0x4
    unsigned short pad;    // 0x6
    SafeAllocator* alloc;  // 0x8
};

// USA: func_0207c164
ARM void AllocateArray0207c164(struct Foo0207c164* obj, int count) {
    obj->ptr = obj->alloc->Allocate(count << 2);
    if (obj->ptr != NULL) {
        obj->count = count;
    }
}
