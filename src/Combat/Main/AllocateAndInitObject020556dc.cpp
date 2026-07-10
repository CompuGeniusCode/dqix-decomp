#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_02056d10(void* obj);

// USA: func_020556dc
ARM bool AllocateAndInitObject020556dc(void** out, SafeAllocator* alloc) {
    void* p;
    if (alloc == NULL) return false;
    p = alloc->Allocate(0x170);
    *out = p;
    if (p == NULL) return false;
    func_02056d10(p);
    return true;
}
