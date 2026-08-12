#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ClearTarget0205a234;
extern void ClearField0And40205a234(struct ClearTarget0205a234* target);

struct List0204af64;
extern void ResetList0204af64(struct List0204af64* obj);

extern "C" void func_0204c684(char* obj);

struct InitTarget0205cfd4;
extern void InitStruct0205cfd4(struct InitTarget0205cfd4* s);

extern void ClearFields_021e20c0(void* p);

// USA: func_ov003_0216e02c
extern "C" ARM void func_ov003_0216e02c(char* self, SafeAllocator* alloc) {
    if (alloc == 0) {
        return;
    }

    *(SafeAllocator**)(self + 0xd0) = alloc;
    *(void**)(self + 0x3c) = alloc->Allocate(0xbc);
    *(void**)(self + 0x40) = (*(SafeAllocator**)(self + 0xd0))->Allocate(0x40);
    *(void**)(self + 0x44) = (*(SafeAllocator**)(self + 0xd0))->Allocate(0x1c0);
    *(void**)(self + 0x60) = (*(SafeAllocator**)(self + 0xd0))->Allocate(0x370);
    *(void**)(self + 0x64) = (*(SafeAllocator**)(self + 0xd0))->Allocate(8);
    *(void**)(self + 0xd4) = (*(SafeAllocator**)(self + 0xd0))->Allocate(0x4c);

    ClearField0And40205a234((struct ClearTarget0205a234*)*(void**)(self + 0x64));

    void* buf = (*(SafeAllocator**)(self + 0xd0))->Allocate(0x400);
    ((SafeAllocator*)(self + 0xbc))->CreateTypeA(buf, 0x400);
    ((SafeAllocator*)(self + 0xbc))->Reset();

    InitStruct0205cfd4((struct InitTarget0205cfd4*)*(void**)(self + 0x3c));

    for (int i = 0; i < 2; i++) {
        ResetList0204af64((struct List0204af64*)(*(char**)(self + 0x40) + (i << 5)));
    }

    for (int i = 0; i < 2; i++) {
        func_0204c684(*(char**)(self + 0x44) + i * 0xe0);
    }

    ClearFields_021e20c0(*(void**)(self + 0xd4));
}
