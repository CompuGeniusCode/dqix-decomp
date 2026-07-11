#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

// USA: func_02012db0
ARM void* AllocateFromAllocatorUnion(AllocatorUnion* alloc, unsigned int size) {
    return alloc->Allocate(size);
}
