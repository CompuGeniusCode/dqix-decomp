#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

// USA: func_02012da4
ARM void TailForward02012da4(AllocatorUnion* alloc, void* data) {
    alloc->Free(data);
}
