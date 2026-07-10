#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct List020348b4 {
    char pad[0x10];
    void* buf;                // 0x10
    unsigned short used;      // 0x14
    unsigned short capacity;  // 0x16
};

// USA: func_020348b4
ARM void AllocateList020348b4(struct List020348b4* self, SafeAllocator* alloc, int count) {
    self->buf = alloc->Allocate(count * 0xc);
    if (self->buf != NULL) {
        self->capacity = count;
        self->used = 0;
    } else {
        self->capacity = 0;
        self->used = 0;
    }
}
