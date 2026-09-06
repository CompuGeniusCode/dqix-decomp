#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

// USA: func_02012dbc
ARM void FreeIfFlag(AllocatorUnion* alloc, void* data, int flag) {
    if (flag == 0)
        return;
    alloc->Free(data);
}
