#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void LZ77UnCompReadNormalWrite8bit(const void* src, void* dst);

// USA: func_02075654
ARM void* AllocateAndDecompressLZ77_02075654(SafeAllocator* alloc, const void* src, unsigned int* outSize) {
    unsigned int size = *(const unsigned int*)src >> 8;
    *outSize = size;
    void* buf = alloc->Allocate(size);
    if (buf == NULL) return NULL;
    LZ77UnCompReadNormalWrite8bit(src, buf);
    return buf;
}
