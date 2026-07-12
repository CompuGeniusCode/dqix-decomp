#include <globaldefs.h>
void ResetTimersAndBuffers0207e264(unsigned char*);
#include "Memory/SafeAllocator.h"

struct Obj020360d4 {
    unsigned char pad[0x8];
    void* field8;
};

struct Stream0207e3b0;

void SetBufferFlushAndProcess0207e3b0(struct Stream0207e3b0* obj, int src, int size, int arg);

// USA: func_020360d4
ARM int AllocateBufferAndFlush020360d4(struct Obj020360d4* obj, SafeAllocator* alloc, int b, int c, int e) {
    obj->field8 = alloc->Allocate(0xac);
    if (obj->field8 == NULL) return 0;
    ResetTimersAndBuffers0207e264((unsigned char*)(obj->field8));
    SetBufferFlushAndProcess0207e3b0((struct Stream0207e3b0*)obj->field8, b, c, e);
    return 1;
}
