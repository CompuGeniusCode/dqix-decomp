#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Elem02028754 {
    int a;   // 0x0
    int b;   // 0x4
};

struct Array02028754 {
    char pad0;                    // 0x0
    unsigned char count;          // 0x1
    char pad[6];                  // 0x2..0x7
    struct Elem02028754* buffer;  // 0x8
};

// USA: func_02028754
ARM void AllocateClearArray02028754(struct Array02028754* obj, SafeAllocator* alloc, int count) {
    int i;
    struct Elem02028754* buf;
    obj->buffer = (struct Elem02028754*)alloc->Allocate(count * 8);
    if (obj->buffer == NULL) {
        obj->count = 0;
        return;
    }
    obj->count = count;
    for (i = 0; i < obj->count; i++) {
        buf = obj->buffer + i;
        buf->b = 0;
        buf->a = 0;
    }
}
