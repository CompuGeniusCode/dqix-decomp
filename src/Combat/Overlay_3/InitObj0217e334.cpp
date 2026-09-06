#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c {
    signed char byte0;
    signed char byte1;
    signed char byte2;
    signed char byte3;
};
void ResetByteHeader(struct ByteHeader0204693c* p);

struct Obj0217e334 {
    struct ByteHeader0204693c hdr;
    char pad4[4];
    int field8;
    class SafeAllocator alloc;
    int field20;
    unsigned char field24;
};

// USA: func_ov003_0217e334
ARM void InitObj0217e334(struct Obj0217e334* self) {
    ResetByteHeader(&self->hdr);
    self->hdr.byte0 = 0x11;
    self->field8 = 0;
    self->alloc.ResetAllocatorPointer();
    self->field20 = 0;
    self->field24 = 0xff;
}
