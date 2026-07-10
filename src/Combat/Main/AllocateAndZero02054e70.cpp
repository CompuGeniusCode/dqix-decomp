#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct T02054e70 {
    int f0;
    int f4;
    int f8;
};

// USA: func_02054e70
ARM int AllocateAndZero02054e70(struct T02054e70** out, SafeAllocator* alloc) {
    struct T02054e70* p;
    if (alloc == NULL) return 0;
    p = (struct T02054e70*)alloc->Allocate(0xc);
    *out = p;
    if (p == NULL) return 0;
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
    return 1;
}
