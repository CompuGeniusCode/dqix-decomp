#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj0204c7a8 {
    char pad0[0x8];
    int field8;
    char pad_c[0xd4 - 0xc];
    void* fieldd4;
};

// USA: func_0204c7a8
ARM void AllocateBuffer0204c7a8(struct Obj0204c7a8* obj, SafeAllocator* alloc, int val, unsigned int len) {
    obj->fieldd4 = alloc->Allocate(len);
    obj->field8 = val;
}
