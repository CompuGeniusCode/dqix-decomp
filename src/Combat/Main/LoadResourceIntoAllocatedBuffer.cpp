#include <globaldefs.h>

struct Obj0207e378;
extern void SetBufferAndFlushCache0207e378(struct Obj0207e378* obj, void* alloc, void* src, unsigned int size, int arg5);
extern void CleanInvalidateDataCacheRange(int addr, int size);
extern void ShiftInBitOnGlobalObject();
extern void HalveGlobalObjectCounter();
extern int data_0211e33c;
extern "C" void* func_02075098(void* key, void* table, int* outSize);

struct FlagsAt0xa80207e304 {
    char pad[0xa8];
    int flags;
};

// USA: func_0207e304
ARM void LoadResourceIntoAllocatedBuffer(void* a, void* b, void* c, int d) {
    if (c == NULL) return;
    ShiftInBitOnGlobalObject();
    int size;
    void* addr = func_02075098(b, &data_0211e33c, &size);
    if (addr == NULL) {
        struct FlagsAt0xa80207e304* obj = (struct FlagsAt0xa80207e304*)a;
        obj->flags &= ~1;
    } else {
        CleanInvalidateDataCacheRange((int)addr, size);
        SetBufferAndFlushCache0207e378((struct Obj0207e378*)a, c, addr, size, d);
    }
    HalveGlobalObjectCounter();
}
