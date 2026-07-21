#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" int func_ov017_0218b5b0(void);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);

extern int data_02114e20;

struct Obj021a9714 {
    char pad[8];
    unsigned char byte8;
    char pad1[0xc - 0x9];
    SafeAllocator allocator;
    char pad2[0x20 - 0xc - sizeof(SafeAllocator)];
    int field20;
};

// USA: func_ov017_021a9714
ARM void ResetAllocatorAndClearBits_021a9714(struct Obj021a9714* self) {
    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
    }
    self->allocator.ResetAllocatorPointer();
    self->byte8 = 0;
    self->field20 = 0;
    int h = func_ov017_0218b5b0();
    ClearBitsInField4((unsigned int*)h, 0xc0);
}
