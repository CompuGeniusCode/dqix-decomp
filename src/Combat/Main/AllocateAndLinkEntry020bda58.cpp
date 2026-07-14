#include <globaldefs.h>
#include "Memory/HMRFAllocator.h"

struct Obj020bda58 {
    HMRFAllocator* allocator;
    SignedAllocatorList list;
};

// USA: func_020bda58
ARM void* AllocateAndLinkEntry020bda58(struct Obj020bda58* obj, unsigned int size, int a2, int a3, int a4) {
    unsigned int allocSize = ((size + 0x1f) & ~0x1f) + 0x20;
    unsigned char* entry = (unsigned char*)obj->allocator->Allocate(allocSize, 0x20);
    if (entry == NULL) {
        return NULL;
    }
    SignedAllocatorList* target = (SignedAllocatorList*)obj->list.ElementBefore(NULL);
    *(int*)(entry + 0x8) = size;
    *(int*)(entry + 0xc) = a2;
    *(int*)(entry + 0x10) = a3;
    *(int*)(entry + 0x14) = a4;
    target->InsertAtEnd((SignedAllocatorHeader*)entry);
    return entry + 0x20;
}
