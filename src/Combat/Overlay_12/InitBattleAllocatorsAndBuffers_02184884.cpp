#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct0215efb8;
ARM void InitStruct0215efb8(Struct0215efb8* s);

struct ResetLayout_0215e6d8;
ARM void ResetStruct_0215e6d8(ResetLayout_0215e6d8* s);

ARM int LoadBattleBlock020ac460(void* dst);

// USA: func_ov012_02184884  (semantic: InitBattleAllocatorsAndBuffers_02184884)
extern "C" ARM void func_ov012_02184884(char* self, SafeAllocator* alloc) {
    if (alloc == 0) return;

    void* p0 = alloc->Allocate(0x28);
    *(void**)(self + 0x0) = p0;
    if (p0 != 0) InitStruct0215efb8((Struct0215efb8*)p0);

    void* p4 = alloc->Allocate(0x10);
    *(void**)(self + 0x4) = p4;
    if (p4 != 0) ResetStruct_0215e6d8((ResetLayout_0215e6d8*)p4);

    ((SafeAllocator*)(self + 0x20))->CreateTypeA(alloc->Allocate(0x14c00), 0x14c00);
    ((SafeAllocator*)(self + 0x34))->CreateTypeA(alloc->Allocate(0x2400), 0x2400);
    ((SafeAllocator*)(self + 0x48))->CreateTypeA(alloc->Allocate(0x9400), 0x9400);
    ((SafeAllocator*)(self + 0x5c))->CreateTypeA(alloc->Allocate(0x800), 0x800);
    ((SafeAllocator*)(self + 0x70))->CreateTypeA(alloc->Allocate(0x1800), 0x1800);
    ((SafeAllocator*)(self + 0x84))->CreateTypeA(alloc->Allocate(0x5400), 0x5400);
    ((SafeAllocator*)(self + 0x98))->CreateTypeA(alloc->Allocate(0x400), 0x400);

    *(void**)(self + 0x1000 + 0x364) = alloc->Allocate(0x2f8);
    *(void**)(self + 0x1000 + 0x35c) = alloc->Allocate(0x54);
    *(void**)(self + 0x1000 + 0x360) = alloc->Allocate(0x8);
    *(void**)(self + 0x1000 + 0x36c) = alloc->Allocate(0x78);
    *(void**)(self + 0x1000 + 0x368) = alloc->Allocate(0x54);
    *(void**)(self + 0x1000 + 0x3ac) = alloc->Allocate(0x72);
    *(void**)(self + 0x1000 + 0x3b4) = alloc->Allocate(0x3c00);

    void* p3bc = alloc->Allocate(0xf2);
    *(void**)(self + 0x1000 + 0x3bc) = p3bc;
    memset(p3bc, 0, 0xf2);

    void* p3c0 = alloc->Allocate(0x12);
    *(void**)(self + 0x1000 + 0x3c0) = p3c0;
    memset(p3c0, 0, 0x12);

    void* p3c8 = alloc->Allocate(0x38c);
    *(void**)(self + 0x1000 + 0x3c8) = p3c8;
    memset(p3c8, 0, 0x38c);

    void* p3cc = alloc->Allocate(0x3c);
    *(void**)(self + 0x1000 + 0x3cc) = p3cc;
    memset(p3cc, 0, 0x3c);

    LoadBattleBlock020ac460(*(void**)(self + 0x1000 + 0x3cc));

    void* p3d0 = alloc->Allocate(0x400);
    *(void**)(self + 0x1000 + 0x3d0) = p3d0;
    memset(p3d0, 0, 0x400);
}
