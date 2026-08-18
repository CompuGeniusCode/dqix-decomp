#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Obj0207e378;
extern void SetBufferAndFlushCache0207e378(struct Obj0207e378* obj, void* alloc, void* src, unsigned int size, int arg5);
extern void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern int data_0211e33c;
void* LoadFileIntoMemory(const char*, void*, unsigned int*);

struct FlagsAt0xa80207e304 {
    char pad[0xa8];
    int flags;
};

// USA: func_0207e304
ARM void LoadResourceIntoAllocatedBuffer(void* a, void* b, void* c, int d) {
    if (c == NULL) return;
    BackgroundLoader::AddLockGlobal();
    int size;
    void* addr = LoadFileIntoMemory((const char*)b, &data_0211e33c, (unsigned int*)&size);
    if (addr == NULL) {
        struct FlagsAt0xa80207e304* obj = (struct FlagsAt0xa80207e304*)a;
        obj->flags &= ~1;
    } else {
        CleanInvalidateCacheRange(addr, size);
        SetBufferAndFlushCache0207e378((struct Obj0207e378*)a, c, addr, size, d);
    }
    BackgroundLoader::RemoveLockGlobal();
}
