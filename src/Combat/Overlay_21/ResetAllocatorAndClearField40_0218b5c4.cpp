#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void TailForward02012da4(AllocatorUnion*, void*);
extern AllocatorUnion data_02114e20;

struct Obj0218b5c4 {
    char pad[0x2c];
    SafeAllocator allocator;
    char pad2[0x40 - 0x2c - sizeof(SafeAllocator)];
    int field40;
};

// USA: func_ov021_0218b5c4
ARM void ResetAllocatorAndClearField40_0218b5c4(struct Obj0218b5c4* self) {
    void* handle = self->allocator.GetSignedAllocator();
    self->allocator.Destroy();
    TailForward02012da4(&data_02114e20, handle);
    self->field40 = 0;
}
