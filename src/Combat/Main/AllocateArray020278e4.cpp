#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Array020278e4 {
    char pad[0x2c];
    void* buffer;   // 0x2c
    int count;      // 0x30
    int capacity;   // 0x34
};

// USA: func_020278e4
ARM void AllocateArray020278e4(struct Array020278e4* obj, int capacity, SafeAllocator* alloc) {
    obj->buffer = alloc->Allocate(capacity * 0x10);
    obj->count = 0;
    obj->capacity = capacity;
}
