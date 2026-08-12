#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// USA: func_ov003_0215f8cc  (semantic: InitEightAllocators_0215f8cc)
extern "C" ARM void func_ov003_0215f8cc(void* self, SafeAllocator* other) {
    if (other == 0) return;

    void* buf = other->Allocate(0x1000);
    ((SafeAllocator*)((char*)self + 0x228))->CreateTypeA(buf, 0x1000);

    buf = other->Allocate(0x7000);
    ((SafeAllocator*)((char*)self + 0x23c))->CreateTypeA(buf, 0x7000);

    buf = other->Allocate(0x2000);
    ((SafeAllocator*)((char*)self + 0x264))->CreateTypeA(buf, 0x2000);

    buf = other->Allocate(0x7400);
    ((SafeAllocator*)((char*)self + 0x278))->CreateTypeA(buf, 0x7400);

    buf = other->Allocate(0x4c00);
    ((SafeAllocator*)((char*)self + 0x28c))->CreateTypeA(buf, 0x4c00);

    buf = other->Allocate(0xc00);
    ((SafeAllocator*)((char*)self + 0x2a0))->CreateTypeA(buf, 0xc00);

    buf = other->Allocate(0x3c00);
    ((SafeAllocator*)((char*)self + 0x2b4))->CreateTypeA(buf, 0x3c00);

    buf = other->Allocate(0x200);
    ((SafeAllocator*)((char*)self + 0x2c8))->CreateTypeA(buf, 0x200);
}
