#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

struct Obj0207e378 {
    char pad[0x5c];
    void* buf;         // 0x5c
    unsigned int len;  // 0x60
};

struct Obj0207e3e0;
extern void SetBufferFromAllocator0207e3e0(struct Obj0207e3e0* obj, AllocatorUnion* alloc, void* src, unsigned int size);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" void func_0207e44c(struct Obj0207e378* obj, int arg);

// USA: func_0207e378
ARM void SetBufferAndFlushCache0207e378(struct Obj0207e378* obj, void* alloc, void* src, unsigned int size, int arg5) {
    if (alloc != NULL && src != NULL && size != 0) {
        SetBufferFromAllocator0207e3e0((struct Obj0207e3e0*)obj, (AllocatorUnion*)alloc, src, size);
        CleanInvalidateCacheRange((const void*)((int)obj->buf), (int)obj->len);
        func_0207e44c(obj, arg5);
    }
}
