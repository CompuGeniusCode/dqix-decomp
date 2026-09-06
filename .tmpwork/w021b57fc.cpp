#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);
int GetGlobalField0x1c020421a0();

// USA: func_ov017_021b57fc
ARM void InitState_021b57fc(unsigned char* self) {
    ResetByteHeader((struct ByteHeader0204693c*)self);
    unsigned int poolVal = 0xffff;
    self[0x0] = 0x15;
    *(int*)(self + 0x8) = 0;
    self[0xc] = 0;
    *(unsigned short*)(self + 0x10) = poolVal;
    *(int*)(self + 0x1c) = 0;
    *(unsigned short*)(self + 0xe) = 0;
    *(int*)(self + 0x20) = 0;
    *(int*)(self + 0x24) = 0;
    int negOne = poolVal - 0x10000;
    *(int*)(self + 0x28) = negOne;
    *(unsigned short*)(self + 0x12) = poolVal;
    self[0x16] = 0x3d;
    *(int*)(self + 0x38) = 0;
    self[0x17] = 0;
    *(unsigned short*)(self + 0x14) = (unsigned short)negOne;
    *(unsigned short*)(self + 0x18) = 0x1f4;

    ((SafeAllocator*)(self + 0x40))->ResetAllocatorPointer();
    ((SafeAllocator*)(self + 0x58))->ResetAllocatorPointer();

    *(int*)(self + 0x3c) = *(int*)(GetGlobalField0x1c020421a0() + 0x5c);
    memset((void*)*(int*)(self + 0x3c), 0, 0x960);

    volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
    unsigned int v = *reg;
    unsigned int temp = ((v & 0x1f00) >> 8) | 0x10;
    unsigned int cur = *reg;
    *reg = (cur & ~0x1f00) | (temp << 8);

    self[0x54] = 0;
}
