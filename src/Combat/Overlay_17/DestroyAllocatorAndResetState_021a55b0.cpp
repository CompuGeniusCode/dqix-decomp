#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern "C" void func_020a0c0c(void);
struct ResetObj020d7a5c;
struct ResetObj020d7a5c* GetGlobalResetObj020d7a50();
struct Obj020d7aa0;
void TeardownAndResetState020d7aa0(struct Obj020d7aa0* obj);

extern int data_02114e20;

struct Obj021a55b0 {
    char pad[0x8];
    int field8;
    SafeAllocator allocator;
};

// USA: func_ov017_021a55b0  (semantic: DestroyAllocatorAndResetState_021a55b0)
extern "C" ARM void func_ov017_021a55b0(struct Obj021a55b0* self) {
    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
        func_020a0c0c();
    }
    TeardownAndResetState020d7aa0((struct Obj020d7aa0*)GetGlobalResetObj020d7a50());
    self->allocator.ResetAllocatorPointer();
    self->field8 = 0;
}
