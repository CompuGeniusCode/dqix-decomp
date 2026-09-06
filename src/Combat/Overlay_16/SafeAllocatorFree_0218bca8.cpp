#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern char data_ov016_0219d0c0[];

// USA: func_ov016_0218bca8
ARM void SafeAllocatorFree_0218bca8(void* data) {
    SafeAllocator* alloc = *(SafeAllocator**)(data_ov016_0219d0c0 + 8);
    alloc->Free(data);
}
