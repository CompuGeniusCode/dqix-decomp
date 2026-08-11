#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// USA: func_ov013_02184cf0  (semantic: InitAllocators02184cf0)
extern "C" ARM void func_ov013_02184cf0(void* self, SafeAllocator* other) {
    if (other == 0) return;

    if (*(unsigned char*)((char*)self + 0x640) != 0) {
        void* buf = other->Allocate(0xc00);
        ((SafeAllocator*)((char*)self + 0x60c))->CreateTypeA(buf, 0xc00);
        return;
    }

    unsigned int maxAlloc = other->GetMaxPossibleAllocation();
    void* buf = other->Allocate(maxAlloc);
    ((SafeAllocator*)self)->CreateTypeA(buf, maxAlloc);
    ((SafeAllocator*)self)->Reset();
    void* buf2 = ((SafeAllocator*)self)->Allocate(0xc00);
    ((SafeAllocator*)((char*)self + 0x60c))->CreateTypeA(buf2, 0xc00);
}
