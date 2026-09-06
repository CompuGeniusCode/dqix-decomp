#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ElementArray020e5850 {
    void* data;
    int capacity;
    int size;
};

// USA: func_020e5850
ARM void AllocateElementArray020e5850(struct ElementArray020e5850* self, SafeAllocator* alloc, int count) {
    self->data = alloc->Allocate(count * 0x14);
    self->capacity = count;
    self->size = 0;
}
