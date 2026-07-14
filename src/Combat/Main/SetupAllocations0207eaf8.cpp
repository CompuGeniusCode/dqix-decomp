#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// USA: func_0207eaf8
ARM void SetupAllocations0207eaf8(unsigned char* obj, SafeAllocator* allocator, unsigned int flags) {
    if (allocator != NULL) {
        if (*(void**)(obj + 0x90) == NULL && (flags & 1)) {
            unsigned char* sub = *(unsigned char**)(obj + 0x4);
            *(void**)(obj + 0x90) = allocator->Allocate(sub[0x17] * 0x58);
        }
        if (*(void**)(obj + 0x94) == NULL && (flags & 2)) {
            unsigned char* sub = *(unsigned char**)(obj + 0x4);
            *(void**)(obj + 0x94) = allocator->Allocate(sub[0x18] * 0x38);
        }
    }
    if (flags & 4) return;
    int a = *(int*)(obj + 0x90);
    if (a != 0) *(int*)(obj + 0x34) = a;
    int b = *(int*)(obj + 0x94);
    if (b != 0) *(int*)(obj + 0x38) = b;
    *(int*)(obj + 0xa8) |= 4;
}
