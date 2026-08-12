#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ArrayHolder021e20ec {
    void* data;
    int count;
};

// USA: func_ov025_021e20ec  (semantic: InitArray_021e20ec)
extern "C" ARM void* func_ov025_021e20ec(struct ArrayHolder021e20ec* obj, SafeAllocator* alloc) {
    obj->count = 0x51;
    return obj->data = alloc->Allocate(obj->count * 0xc);
}
