#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj02054f3c {
    int field0;
    int field4;
    int field8;
};

// USA: func_02054f3c
ARM bool AllocateAndClear12Bytes02054f3c(struct Obj02054f3c** out, SafeAllocator* alloc) {
    struct Obj02054f3c* p;
    if (alloc == NULL) return false;
    p = (struct Obj02054f3c*)alloc->Allocate(0xc);
    *out = p;
    if (p == NULL) return false;
    p->field0 = 0;
    p->field4 = 0;
    p->field8 = 0;
    return true;
}
