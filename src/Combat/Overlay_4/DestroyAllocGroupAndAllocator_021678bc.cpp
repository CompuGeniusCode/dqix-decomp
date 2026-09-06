#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct StructAllocGroup0208ba54;
void DestroyStructAllocGroup0208ba54(struct StructAllocGroup0208ba54* self);

struct Obj021678bc {
    unsigned char pad[0x20];
    SafeAllocator allocator;
    unsigned char pad2[0x34 - 0x20 - sizeof(SafeAllocator)];
    struct StructAllocGroup0208ba54* group;
};

// USA: func_ov004_021678bc  (semantic: DestroyAllocGroupAndAllocator_021678bc)
extern "C" ARM void func_ov004_021678bc(struct Obj021678bc* self) {
    DestroyStructAllocGroup0208ba54((struct StructAllocGroup0208ba54*)((char*)self + 0x34));
    self->allocator.Destroy();
}
