#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void LZ77UnCompReadNormalWrite8bit(const void* src, void* dst);

// USA: func_02075608
ARM void* DecompressLZ77ToAllocatorTail_02075608(SafeAllocator* alloc, const void* src, unsigned int* outSize) {
    *outSize = *(const unsigned int*)src >> 8;
    char* end = (char*)alloc->GetSignedAllocator() + alloc->GetSize();
    void* dst = end - *outSize;
    LZ77UnCompReadNormalWrite8bit(src, dst);
    return dst;
}
