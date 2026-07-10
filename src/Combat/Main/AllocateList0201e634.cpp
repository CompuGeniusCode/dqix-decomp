#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct List0201e634 {
    char pad[0x24];
    void* buf;       // +0x24
    int count;       // +0x28
    int capacity;    // +0x2c
};

// USA: func_0201e634
ARM void AllocateList0201e634(struct List0201e634* self, int capacity, SafeAllocator* alloc) {
    self->buf = alloc->Allocate(capacity * 0x74);
    self->count = 0;
    self->capacity = capacity;
}
