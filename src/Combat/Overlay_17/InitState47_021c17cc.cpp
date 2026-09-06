#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

struct Obj021c17cc {
    unsigned char byte0;
    unsigned char pad1[7];
    SafeAllocator alloc;
    unsigned char b1c;
    unsigned char b1d;
    unsigned char pad1e[2];
    int f20;
};

// USA: func_ov017_021c17cc  (semantic: InitState47_021c17cc)
extern "C" ARM void func_ov017_021c17cc(Obj021c17cc* p) {
    ResetByteHeader((ByteHeader0204693c*)p);
    p->byte0 = 0x2f;
    p->alloc.ResetAllocatorPointer();
    p->b1c = 0;
    p->f20 = 0;
    p->b1d = 0;
}
