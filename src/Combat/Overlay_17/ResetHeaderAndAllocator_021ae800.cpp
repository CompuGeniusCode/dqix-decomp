#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021ae800 {
    unsigned char byte0;
    char pad0[7];
    unsigned char byte8;
    unsigned char byte9;
    short halfA;
    short halfC;
    char pad1[0x2c - 0x10];
    SafeAllocator allocator;
};

// USA: func_ov017_021ae800
ARM void ResetHeaderAndAllocator_021ae800(Obj021ae800* self) {
    ResetByteHeader((ByteHeader0204693c*)self);
    self->byte0 = 0x23;
    self->byte8 = 0;
    self->halfA = 0;
    self->halfC = 0;
    self->allocator.ResetAllocatorPointer();
    {
        volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
        unsigned int extracted = (*reg & 0x1f00) >> 8;
        *reg = (*reg & ~0x1f00) | ((extracted | 0x10) << 8);
    }
    self->byte9 = 0;
}
