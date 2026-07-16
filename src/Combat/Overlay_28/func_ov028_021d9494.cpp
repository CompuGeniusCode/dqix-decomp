#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj021d977c {
    char pad[0x44];
    class SafeAllocator allocator;
};

extern "C" ARM void func_ov028_021d9494(struct Obj021d977c* obj);

// USA: func_ov028_021d977c
ARM struct Obj021d977c* InitAllocatorAndReset_021d977c(struct Obj021d977c* obj) {
    obj->allocator.ResetAllocatorPointer();
    func_ov028_021d9494(obj);
    return obj;
}
