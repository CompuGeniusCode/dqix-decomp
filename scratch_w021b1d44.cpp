#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "System/Memory.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021b1d44 {
    signed char tag;        // 0x0
    signed char pad1[7];    // 0x1
    int field8;             // 0x8
    signed char pad2[0x14]; // 0xc (allocator region)
    unsigned char field20;  // 0x20
    unsigned char flags21;  // 0x21
    unsigned char pad3[2];  // 0x22
    int field24;            // 0x24
    unsigned char field28;  // 0x28
    unsigned char field29;  // 0x29
    unsigned char buf2a[8]; // 0x2a
    unsigned char field32;  // 0x32
    unsigned char pad4;     // 0x33
    int field34;            // 0x34
    int field38;            // 0x38
    int arr3c[8];           // 0x3c
};

// USA: func_ov017_021b1d44
ARM int InitObj021b1d44(struct Obj021b1d44* self, unsigned char flags, int hasBuf) {
    ResetByteHeader((ByteHeader0204693c*)self);
    self->tag = 0x2c;
    self->field8 = 0;
    self->field20 = 0;
    self->flags21 = flags;
    self->field24 = 0;
    ((SafeAllocator*)((char*)self + 0xc))->ResetAllocatorPointer();
    self->field32 = 0;
    if (hasBuf) {
        self->field28 = 0;
        self->field29 = 0;
        VectorizedMemset(self->buf2a, 0, 8);
    }
    self->field34 = 0;
    self->field38 = 0;
    if (self->flags21 & 0x40) {
        for (int i = 0; i < 8; i++) {
            self->arr3c[i] = -1;
        }
        return 0;
    }
    char* p = (char*)GetBattleStruct();
    p += 0x26c;
    p += 0x5d00;
    unsigned short v = *(unsigned short*)(p + 0xc);
    v = (unsigned short)((v << 19) >> 19);
    if (v & 0x8) return 1;
    if (self->flags21 & 0x4) return 1;
    if (self->flags21 & 0x2) return 1;
    if (!(self->flags21 & 0x20)) {
        self->flags21 |= 0x10;
    }
    return 1;
}
