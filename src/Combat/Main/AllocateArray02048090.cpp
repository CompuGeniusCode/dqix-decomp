#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Array02048090 {
    int count;      // 0x0
    void* buffer;   // 0x4
};

// USA: func_02048090
ARM void AllocateArray02048090(struct Array02048090* obj, int count, SafeAllocator* alloc) {
    obj->count = count;
    obj->buffer = alloc->Allocate(obj->count * 0x1e);
}
