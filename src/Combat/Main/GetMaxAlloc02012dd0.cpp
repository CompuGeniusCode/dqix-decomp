#include <globaldefs.h>
#include "Memory/HPXEAllocator.h"

struct Struct02012dd0 {
    void* unk0;
    HPXEAllocator* alloc;
};

// USA: func_02012dd0
ARM unsigned int GetMaxAlloc02012dd0(Struct02012dd0* self) {
    return self->alloc->GetMaxPossibleAllocation(4);
}
