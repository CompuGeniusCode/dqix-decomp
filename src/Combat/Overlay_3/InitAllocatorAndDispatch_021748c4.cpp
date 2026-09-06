#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);

extern "C" void func_ov023_021dc9e8(void* a, void* b, int key, void* c, int flags);
extern "C" void func_ov023_021dc134(void* a, int key, int flag);
extern "C" void func_ov023_021dbfd0(void* a, void* b);

// USA: func_ov003_021748c4  (semantic: InitAllocatorAndDispatch_021748c4)
extern "C" ARM void func_ov003_021748c4(unsigned char* self) {
    OrBitsIntoField0((unsigned int*)GetDataPtr02114e04_020d6c00(), 1);
    unsigned short flags = *(unsigned short*)(self + 0x1046);
    unsigned char* field4 = *(unsigned char**)(self + 0x4);
    if (flags & 0x800) {
        return;
    }
    SafeAllocator* alloc = (SafeAllocator*)(field4 + 0x28);
    if (flags & 0x80) {
        alloc->Reset();
        short key = *(short*)(self + 0x103a);
        func_ov023_021dc9e8(self + 0x3c, alloc, key, self + 0x874, 0x450);
        *(unsigned short*)(self + 0x1046) |= 0x800;
    } else {
        alloc->Reset();
        short key = *(short*)(self + 0x103a);
        func_ov023_021dc134(self + 0x3c, key, 0);
        *(unsigned short*)(self + 0x7b0) |= 0x450;
        func_ov023_021dbfd0(self + 0x3c, alloc);
        *(void**)(self + 0x84) = self + 0x874;
        *(unsigned short*)(self + 0x1046) |= 0x880;
    }
}
