#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct0205a198;
void Init0205a198(struct Struct0205a198* p);

struct ClearTarget0205a234;
void ClearField0And40205a234(struct ClearTarget0205a234* target);

// USA: func_ov003_021726f8
extern "C" ARM void func_ov003_021726f8(char* obj, SafeAllocator* allocator) {
    int i;

    if (allocator == 0) return;

    *(SafeAllocator**)(obj + 0x1c0) = allocator;
    *(void**)(obj + 0x128) = allocator->Allocate(0x208);
    *(void**)(obj + 0x12c) = (*(SafeAllocator**)(obj + 0x1c0))->Allocate(8);

    for (i = 0; i < 0xd; i++) {
        Init0205a198((struct Struct0205a198*)(*(char**)(obj + 0x128) + i * 0x28));
    }

    ClearField0And40205a234((struct ClearTarget0205a234*)*(void**)(obj + 0x12c));

    void* p1 = (*(SafeAllocator**)(obj + 0x1c0))->Allocate(0x1000);
    ((SafeAllocator*)(obj + 0x1ac))->CreateTypeA(p1, 0x1000);
    ((SafeAllocator*)(obj + 0x1ac))->Reset();

    void* p2 = (*(SafeAllocator**)(obj + 0x1c0))->Allocate(0x2800);
    ((SafeAllocator*)(obj + 0x184))->CreateTypeA(p2, 0x2800);
    ((SafeAllocator*)(obj + 0x184))->Reset();

    void* p3 = (*(SafeAllocator**)(obj + 0x1c0))->Allocate(0x400);
    ((SafeAllocator*)(obj + 0x198))->CreateTypeA(p3, 0x400);
    ((SafeAllocator*)(obj + 0x198))->Reset();
}
