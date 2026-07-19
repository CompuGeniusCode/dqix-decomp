#include <globaldefs.h>
#include "System/Memory.h"

void* AllocateFromMainAllocator_0223cf00(unsigned int len, int align);

// USA: func_ov031_0223cf4c  (semantic: AllocateAndZero0223cf4c)
extern "C" ARM void* func_ov031_0223cf4c(int size, int alignAndDir) {
    void* mem = AllocateFromMainAllocator_0223cf00(size, alignAndDir);
    VectorizedMemset(mem, 0, size);
    return mem;
}
