#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c {
    signed char byte0;
    signed char byte1;
    signed char byte2;
    signed char byte3;
};
struct List020727d8 {
    void* entries;
    short capacity;
    short count;
};
void ResetByteHeader(struct ByteHeader0204693c* p);
void ResetListHeader020727d8(struct List020727d8* list);

struct Obj020d8080 {
    struct ByteHeader0204693c header;   // 0x0
    int field4;                          // 0x4
    int field8;                          // 0x8
    struct List020727d8 list;            // 0xc
    SafeAllocator allocator;             // 0x14
};

// USA: func_020d8080
ARM void InitObject020d8080(struct Obj020d8080* self) {
    ResetByteHeader(&self->header);
    self->header.byte0 = 0x43;
    self->field8 = 0;
    ResetListHeader020727d8(&self->list);
    self->allocator.ResetAllocatorPointer();
}
