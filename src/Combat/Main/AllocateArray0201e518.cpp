#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0201e518 {
    char  pad[0x18]; // 0x0..0x17
    void* ptr;       // 0x18
    int   idx;       // 0x1c
    int   count;     // 0x20
};

// USA: func_0201e518
ARM void AllocateArray0201e518(struct Foo0201e518* obj, int count, SafeAllocator* alloc) {
    obj->ptr = alloc->Allocate(count * 0x70);
    obj->idx = 0;
    obj->count = count;
}
