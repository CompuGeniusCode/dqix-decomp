#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct020277c4 {
    char pad[0x20];
    void* buf;
    int used;
    int capacity;
};

// USA: func_020277c4
ARM void InitEntryList020277c4(struct Struct020277c4* obj, int count, SafeAllocator* alloc) {
    obj->buf = alloc->Allocate(count * 0x24);
    obj->used = 0;
    obj->capacity = count;
}
