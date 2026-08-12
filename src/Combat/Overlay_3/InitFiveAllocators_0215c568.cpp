#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_020c9be0(void);
int GetGlobalField0x1c020421a0(void);

// USA: func_ov003_0215c568  (semantic: InitFiveAllocators_0215c568)
extern "C" ARM void func_ov003_0215c568(void* self, SafeAllocator* other) {
    if (other == 0) return;

    void* buf = other->Allocate(0x2000);
    if (buf == 0) func_020c9be0();
    ((SafeAllocator*)self)->CreateTypeA(buf, 0x2000);

    buf = other->Allocate(0x800);
    if (buf == 0) func_020c9be0();
    ((SafeAllocator*)((char*)self + 0x14))->CreateTypeA(buf, 0x800);

    buf = other->Allocate(0x4000);
    if (buf == 0) func_020c9be0();
    ((SafeAllocator*)((char*)self + 0x28))->CreateTypeA(buf, 0x4000);

    buf = other->Allocate(0x400);
    if (buf == 0) func_020c9be0();
    ((SafeAllocator*)((char*)self + 0x3c))->CreateTypeA(buf, 0x400);

    buf = other->Allocate(0x2000);
    if (buf == 0) func_020c9be0();
    ((SafeAllocator*)((char*)self + 0x50))->CreateTypeA(buf, 0x2000);

    int g = GetGlobalField0x1c020421a0();
    *(int*)((char*)self + 0x7c) = *(int*)(g + 0x5c);
}
