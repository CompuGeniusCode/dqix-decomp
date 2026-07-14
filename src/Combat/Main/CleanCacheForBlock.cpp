#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

struct CacheBlock0207e434 {
    char pad[0x5c];
    int addr;
    int size;
};

// USA: func_0207e434
ARM void CleanCacheForBlock(struct CacheBlock0207e434* obj) {
    CleanInvalidateCacheRange((const void*)(obj->addr), obj->size);
}
