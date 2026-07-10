#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct List020347e8 {
    char pad[0x8];
    void* buf;                // 0x8
    unsigned short capacity;  // 0xc
    unsigned short used;      // 0xe
};

// USA: func_020347e8
ARM void AllocateList020347e8(struct List020347e8* self, SafeAllocator* alloc, int count) {
    self->buf = alloc->Allocate(count * 0xc);
    if (self->buf != NULL) {
        self->capacity = count;
        self->used = 0;
    } else {
        self->capacity = 0;
        self->used = 0;
    }
}
