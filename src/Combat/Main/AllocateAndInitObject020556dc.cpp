#include <globaldefs.h>
void ResetObj02056d10(struct Obj02056d10*);
#include "Memory/SafeAllocator.h"


// USA: func_020556dc
ARM bool AllocateAndInitObject020556dc(void** out, SafeAllocator* alloc) {
    void* p;
    if (alloc == NULL) return false;
    p = alloc->Allocate(0x170);
    *out = p;
    if (p == NULL) return false;
    ResetObj02056d10((struct Obj02056d10*)(p));
    return true;
}
