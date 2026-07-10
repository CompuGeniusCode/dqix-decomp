#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0201e25c {
    void* ptr;   // 0x0
    int   idx;   // 0x4
    int   count; // 0x8
};

// USA: func_0201e25c
ARM void AllocateArray0201e25c(struct Foo0201e25c* obj, int count, SafeAllocator* alloc) {
    obj->ptr = alloc->Allocate(count * 0x58);
    obj->idx = 0;
    obj->count = count;
}
