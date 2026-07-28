#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void* ResetOverlayAndAllocator_0219bf74(void);

struct Obj0217bd38 {
    SafeAllocator* field0;
    SafeAllocator alloc4;
    SafeAllocator alloc18;
    SafeAllocator alloc2c;
};

// USA: func_ov003_0217bd38  (semantic: InitAllocators_0217bd38)
extern "C" ARM void func_ov003_0217bd38(Obj0217bd38* self) {
    self->field0 = (SafeAllocator*)ResetOverlayAndAllocator_0219bf74();
    void* p1 = self->field0->Allocate(0x32000);
    self->alloc4.CreateTypeA(p1, 0x32000);
    self->alloc4.Reset();
    void* p2 = self->field0->Allocate(0x6800);
    self->alloc18.CreateTypeA(p2, 0x6800);
    self->alloc18.Reset();
    void* p3 = self->field0->Allocate(0x6800);
    self->alloc2c.CreateTypeA(p3, 0x6800);
    self->alloc2c.Reset();
}
