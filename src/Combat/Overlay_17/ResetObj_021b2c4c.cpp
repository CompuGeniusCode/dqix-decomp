#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021b2c4c {
    unsigned char byte0;
    unsigned char pad0[7];
    int f8;
    SafeAllocator alloc;
};

extern int data_ov017_021d840c;

// USA: func_ov017_021b2c4c  (semantic: ResetObj_021b2c4c)
extern "C" ARM void func_ov017_021b2c4c(Obj021b2c4c* p) {
    ResetByteHeader((ByteHeader0204693c*)p);
    p->byte0 = 0x12;
    p->alloc.ResetAllocatorPointer();
    p->f8 = 0;
    data_ov017_021d840c = 0;
    *((unsigned char*)p + 0x20) = 0xff;
}
