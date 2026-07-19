#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(struct ByteHeader0204693c* p);

extern "C" void func_0208b9a0(void*, int);

struct Obj_021b994c;
extern void ResetFieldsToDefault_021b994c(struct Obj_021b994c* obj);

// USA: func_ov017_021b8d1c  (semantic: InitStateAndFields_021b8d1c)
extern "C" ARM void func_ov017_021b8d1c(unsigned char* base) {
    ResetByteHeader((struct ByteHeader0204693c*)base);
    ((SafeAllocator*)(base + 0x8))->ResetAllocatorPointer();
    ((SafeAllocator*)(base + 0x1c))->ResetAllocatorPointer();
    func_0208b9a0(base + 0x30, 0);
    base[0] = 5;
    *(int*)(base + 0x11c) = 0;
    *(int*)(base + 0x124) = 0;
    *(int*)(base + 0x114) = 0;
    *(int*)(base + 0x118) = 0;
    base[0x128] = 0;
    base[0x129] = 0;
    base[0x137] = 0;
    base[0x138] = 0;
    base[0x139] = 0;
    ResetFieldsToDefault_021b994c((struct Obj_021b994c*)base);
}
