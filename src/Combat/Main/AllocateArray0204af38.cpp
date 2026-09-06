#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0204af38 {
    char _pad0[0x10];
    void* buffer;        // 0x10
    char _pad1[0xa];     // 0x14
    unsigned char count; // 0x1e
};

// USA: func_0204af38
ARM void AllocateArray0204af38(struct Foo0204af38* obj, int count, SafeAllocator* alloc) {
    if (alloc == NULL) return;
    obj->buffer = alloc->Allocate(count * 0x10);
    obj->count = count;
}
