#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct List0201f1f0 {
    char pad[0xc];
    void* buf;       // +0xc
    int count;       // +0x10
    int capacity;    // +0x14
};

// USA: func_0201f1f0
ARM void AllocateList0201f1f0(struct List0201f1f0* self, int capacity, SafeAllocator* alloc) {
    self->buf = alloc->Allocate(capacity * 0x20);
    self->capacity = capacity;
}
