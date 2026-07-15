#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);
extern int data_ov017_021d8474;

struct Obj021c0124 {
    unsigned char byte0;
    unsigned char pad1[7];
    SafeAllocator alloc;
    int f1c;
    unsigned char b20;
};

// USA: func_ov017_021c0124
ARM void InitState32_021c0124(Obj021c0124* p, unsigned char flag) {
    ResetByteHeader((ByteHeader0204693c*)p);
    p->byte0 = 0x20;
    p->alloc.ResetAllocatorPointer();
    data_ov017_021d8474 = 0;
    p->f1c = 0;
    p->b20 = flag;
}
