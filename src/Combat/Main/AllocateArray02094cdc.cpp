#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct AllocDest02094cdc {
    void* ptr;
};

// USA: func_02094cdc
ARM void AllocateArray02094cdc(struct AllocDest02094cdc* obj, int count, SafeAllocator* alloc) {
    obj->ptr = alloc->Allocate(count * 20);
}
