#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// USA: func_020466d0
ARM SafeAllocator* ResetAndReturnAllocator(SafeAllocator* alloc) {
    alloc->ResetAllocatorPointer();
    return alloc;
}
