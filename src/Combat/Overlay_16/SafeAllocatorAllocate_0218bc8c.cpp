#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern char data_ov016_0219d0c0[];

// USA: func_ov016_0218bc8c
ARM void* SafeAllocatorAllocate_0218bc8c(unsigned int len) {
    SafeAllocator* alloc = *(SafeAllocator**)(data_ov016_0219d0c0 + 8);
    return alloc->Allocate(len);
}
