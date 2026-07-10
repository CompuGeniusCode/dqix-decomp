#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct List020346b4 {
    void* buf;                // 0x0
    unsigned short used;      // 0x4
    unsigned short capacity;  // 0x6
};

// USA: func_020346b4
ARM void AllocateEntryList020346b4(struct List020346b4* self, SafeAllocator* alloc, int count) {
    if (alloc == NULL) return;
    self->buf = alloc->Allocate(count * 0x24);
    if (self->buf != NULL) {
        self->used = 0;
        self->capacity = count;
    } else {
        self->used = 0;
        self->capacity = 0;
    }
}
