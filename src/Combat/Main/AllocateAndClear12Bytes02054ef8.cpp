#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj02054ef8 {
    int field0;
    int field4;
    int field8;
};

// USA: func_02054ef8
ARM bool AllocateAndClear12Bytes02054ef8(struct Obj02054ef8** out, SafeAllocator* alloc) {
    struct Obj02054ef8* p;
    if (alloc == NULL) return false;
    p = (struct Obj02054ef8*)alloc->Allocate(0xc);
    *out = p;
    if (p == NULL) return false;
    p->field0 = 0;
    p->field4 = 0;
    p->field8 = 0;
    return true;
}
