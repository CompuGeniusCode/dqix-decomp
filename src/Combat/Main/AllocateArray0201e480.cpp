#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0201e480 {
    char  pad[0xc]; // 0x0..0xb
    void* ptr;      // 0xc
    int   idx;      // 0x10
    int   count;    // 0x14
};

// USA: func_0201e480
ARM void AllocateArray0201e480(struct Foo0201e480* obj, int count, SafeAllocator* alloc) {
    obj->ptr = alloc->Allocate(count * 0x24);
    obj->idx = 0;
    obj->count = count;
}
