#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void* DecompressLZ77ToAllocatorTail_02075608(SafeAllocator* alloc, const void* src, unsigned int* outSize);
void ClearStruct0201e248(void* obj);
void SwapArgsAndCall0201e2b4(int a, int b, int c, int d);

// USA: func_02014390
ARM int DecompressAndInitAt0x6c_02014390(char* obj, const void* src) {
    SafeAllocator* alloc = *(SafeAllocator**)(obj + 0x68);
    unsigned int size;
    void* data = DecompressLZ77ToAllocatorTail_02075608(alloc, src, &size);
    int saved = *(int*)(obj + 0x8);
    ClearStruct0201e248(obj + 0x6c);
    SwapArgsAndCall0201e2b4((int)(obj + 0x6c), (int)alloc, (int)data, (int)size);
    *(int*)(obj + 0x8) = saved;
    return 1;
}
