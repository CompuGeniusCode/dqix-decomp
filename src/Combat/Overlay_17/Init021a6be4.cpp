#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);

struct List020727d8 {
    void* entries;
    short capacity;
    short count;
};
void ResetListHeader020727d8(struct List020727d8* list);

// USA: func_ov017_021a6be4
ARM void Init021a6be4(unsigned char* self) {
    ResetByteHeader((struct ByteHeader0204693c*)self);
    self[0] = 0x3e;
    *(int*)(self + 8) = 0;
    *(int*)(self + 0x44) = -1;
    *(int*)(self + 0xc) = 0;
    self[0x10] = 0;
    ResetListHeader020727d8((struct List020727d8*)(self + 0x14));
    ((SafeAllocator*)(self + 0x1c))->ResetAllocatorPointer();
    ((SafeAllocator*)(self + 0x30))->ResetAllocatorPointer();
}
