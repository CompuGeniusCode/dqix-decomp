#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

// Rounds the request up to a whole word before handing it to AllocatorUnion::Allocate.
extern "C" ARM void* AllocateRoundedToWord(AllocatorUnion* alloc, unsigned int size) {
    void* p = alloc->Allocate((size + 3) & ~3);
    if (p == NULL)
        return NULL;
    return p;
}
