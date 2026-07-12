#include <globaldefs.h>
void ResetTimersAndBuffers0207e264(unsigned char*);
#include "Memory/SafeAllocator.h"

struct Obj02036084 {
    unsigned char pad[0x8];
    void* field8;
};

struct Obj0207e378;
void SetBufferAndFlushCache0207e378(struct Obj0207e378*, void*, void*, unsigned int, int);

// USA: func_02036084
ARM void AllocateAndInitBuffer02036084(struct Obj02036084* obj, SafeAllocator* alloc, int b, int c, int e) {
    if (alloc == NULL || b == 0) return;
    obj->field8 = alloc->Allocate(0xac);
    ResetTimersAndBuffers0207e264((unsigned char*)(obj->field8));
    SetBufferAndFlushCache0207e378((struct Obj0207e378*)obj->field8, (char*)alloc + 4, (void*)b, c, e);
}
