#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj02036084 {
    unsigned char pad[0x8];
    void* field8;
};

extern "C" void func_0207e264(void* self);
extern "C" void func_0207e378(void* self, void* src, int b, int c, int e);

// USA: func_02036084
ARM void AllocateAndInitBuffer02036084(struct Obj02036084* obj, SafeAllocator* alloc, int b, int c, int e) {
    if (alloc == NULL || b == 0) return;
    obj->field8 = alloc->Allocate(0xac);
    func_0207e264(obj->field8);
    func_0207e378(obj->field8, (char*)alloc + 4, b, c, e);
}
