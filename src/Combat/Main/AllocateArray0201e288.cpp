#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0201e288 {
    char  pad[0x30]; // 0x0..0x2f
    void* ptr;       // 0x30
    int   idx;       // 0x34
    int   count;     // 0x38
};

// USA: func_0201e288
ARM void AllocateArray0201e288(struct Foo0201e288* obj, int count, SafeAllocator* alloc) {
    obj->ptr = alloc->Allocate(count * 0x10);
    obj->idx = 0;
    obj->count = count;
}
