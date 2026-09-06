#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj021fbe4c {
    char pad[0x20];
    SafeAllocator allocator;
};

// USA: func_ov023_021fbe4c
ARM void DestroySafeAllocator_021fbe4c(struct Obj021fbe4c* self) {
    if (self->allocator.GetSignedAllocator() == NULL) return;
    self->allocator.Destroy();
}
