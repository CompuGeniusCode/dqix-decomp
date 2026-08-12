#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct InitTarget0205cfd4;
ARM void InitStruct0205cfd4(struct InitTarget0205cfd4* s);
struct List0204af64;
ARM void ResetList0204af64(struct List0204af64* obj);
extern "C" void func_0204c684(void* obj);
struct Struct0205a198;
void Init0205a198(struct Struct0205a198*);
struct ClearTarget0205a234;
void ClearField0And40205a234(struct ClearTarget0205a234* target);

struct Struct0216ae0c {
    char pad0[0x1264];
    void* p264;
    void* p268;
    char pad1[0x12c0 - 0x126c];
    void* p2c0;
    void* p2c4;
    void* p2c8;
    char pad2[0x12d0 - 0x12cc];
    SafeAllocator* alloc;
};

// USA: func_ov003_0216ae0c
extern "C" ARM void func_ov003_0216ae0c(void* objRaw, SafeAllocator* allocator) {
    if (allocator == 0) return;
    struct Struct0216ae0c* obj = (struct Struct0216ae0c*)objRaw;

    obj->alloc = allocator;
    obj->p2c0 = obj->alloc->Allocate(0xbc);
    obj->p2c4 = obj->alloc->Allocate(0x40);
    obj->p2c8 = obj->alloc->Allocate(0xe0);
    InitStruct0205cfd4((struct InitTarget0205cfd4*)obj->p2c0);

    for (int i = 0; i < 2; i++) {
        ResetList0204af64((struct List0204af64*)((char*)obj->p2c4 + i * 0x20));
    }
    for (int i = 0; i < 1; i++) {
        func_0204c684((char*)obj->p2c8 + i * 0xe0);
    }

    obj->p264 = obj->alloc->Allocate(0x258);
    obj->p268 = obj->alloc->Allocate(8);

    for (int i = 0; i < 0xf; i++) {
        Init0205a198((struct Struct0205a198*)((char*)obj->p264 + i * 0x28));
    }
    ClearField0And40205a234((struct ClearTarget0205a234*)obj->p268);
}
